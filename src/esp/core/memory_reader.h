#pragma once

#include "driver_comm.h"
#include "module_resolver.h"
#include "offsets.h"
#include "game_data.h"
#include "config.h"

#include <algorithm>
#include <thread>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace esp {

class MemoryReader {
public:
    MemoryReader(DriverComm& driver, uint32_t pid, uint64_t ga_base, GameState& state)
        : m_driver(driver), m_pid(pid), m_ga_base(ga_base), m_state(state) {}

    ~MemoryReader() { stop(); }

    void start() {
        m_running.store(true, std::memory_order_release);
        m_thread = std::thread(&MemoryReader::worker, this);
    }

    void stop() {
        m_running.store(false, std::memory_order_release);
        if (m_thread.joinable()) m_thread.join();
    }

    bool is_running() const { return m_running.load(std::memory_order_acquire); }

    uint64_t pc_klass() const { return m_pc_klass; }
    uint64_t lp_klass() const { return m_lp_klass; }

    uint64_t lp_instance() { return resolve_local_player(); }

private:
    DriverComm& m_driver;
    uint32_t    m_pid;
    uint64_t    m_ga_base;
    GameState&  m_state;
    std::thread m_thread;
    std::atomic<bool> m_running{false};
    int m_fail_count = 0;

    uint64_t m_cached_all_players_klass    = 0;
    uint64_t m_cached_all_players_sfields  = 0;
    uint64_t m_cached_local_player_klass   = 0;
    uint64_t m_cached_local_player_sfields = 0;

    static bool sane_ptr(uint64_t p) {
        return p >= 0x10000ull && p < 0x7FFFFFFFFFFFull;
    }

    void dump_pointer_chains() {

        uint64_t ap_slot_addr = m_ga_base + offsets::ga::ALL_PLAYERS_CLASS_SLOT;

        uint64_t ap_klass = m_driver.read<uint64_t>(m_pid, ap_slot_addr);

        if (sane_ptr(ap_klass)) {
            uint64_t ap_sfields = m_driver.read<uint64_t>(m_pid,
                ap_klass + offsets::STATIC_FIELDS_OFFSET);

            if (sane_ptr(ap_sfields)) {

                for (int i = 0; i < 8; i++) {
                    uint64_t val = m_driver.read<uint64_t>(m_pid, ap_sfields + i * 8);

                }

                uint64_t list_ptr = m_driver.read<uint64_t>(m_pid,
                    ap_sfields + offsets::ga::ALL_PLAYERS_FIELD_IN_SFIELDS);

                if (sane_ptr(list_ptr)) {
                    uint64_t items = m_driver.read<uint64_t>(m_pid,
                        list_ptr + offsets::list_t::ITEMS_ARRAY);
                    int32_t count = m_driver.read<int32_t>(m_pid,
                        list_ptr + offsets::list_t::SIZE);

                }
            }
        }

        uint64_t lp_slot_addr = m_ga_base + offsets::ga::LOCAL_PLAYER_CLASS_SLOT;

        uint64_t lp_klass = m_driver.read<uint64_t>(m_pid, lp_slot_addr);

        if (sane_ptr(lp_klass)) {
            uint64_t lp_sfields = m_driver.read<uint64_t>(m_pid,
                lp_klass + offsets::STATIC_FIELDS_OFFSET);

            if (sane_ptr(lp_sfields)) {

                for (int i = 0; i < 8; i++) {
                    uint64_t val = m_driver.read<uint64_t>(m_pid, lp_sfields + i * 8);

                }

                uint64_t lp_inst = m_driver.read<uint64_t>(m_pid,
                    lp_sfields + offsets::ga::LOCAL_PLAYER_INSTANCE_OFFSET);

            }
        }

        int32_t gs = m_driver.read<int32_t>(m_pid,
            m_ga_base + offsets::ga::GAME_STATE_SLOT);

    }

    std::string read_il2cpp_string(uint64_t str_ptr) {
        if (!sane_ptr(str_ptr)) return "";

        int32_t len = m_driver.read<int32_t>(m_pid, str_ptr + offsets::il2cpp_string::LENGTH);
        if (len <= 0 || len > 64) return "";

        std::wstring ws = m_driver.read_wstring(m_pid,
            str_ptr + offsets::il2cpp_string::CHARS,
            static_cast<size_t>(len));

        std::string result;
        result.reserve(ws.size());
        for (wchar_t c : ws) {
            if (c == 0) break;
            result += (c < 128) ? static_cast<char>(c) : '?';
        }
        return result;
    }

    static bool sane_heap_ptr(uint64_t p) {
        return sane_ptr(p) && (p & 0x7) == 0;
    }

    uint64_t m_pc_klass = 0;
    uint64_t m_lp_klass = 0;
    uint64_t m_lsh_klass = 0;
    bool     m_class_scan_done = false;

    int32_t  m_pc_list_offset = -1;
    uint64_t m_pc_list_sfields = 0;
    int32_t  m_lp_player_offset = -1;
    bool     m_sfields_probe_done = false;

    int32_t  m_pc_is_local_off = -1;
    int      m_pc_local_probe_attempts = 0;
    bool     m_role_dump_done = false;
    std::vector<uint8_t> m_local_snapshot_prev;
    int32_t  m_local_snapshot_gs = -1;

    bool scan_for_pc_list_owner() {
        if (!m_pc_klass) return false;

        printf("[*] Scanning for class that owns List<PlayerController>...\n");
        auto t0 = std::chrono::steady_clock::now();

        const uint64_t SCAN_START = 0x4E00000;
        const uint64_t SCAN_END   = 0x5A00000;
        const uint32_t CHUNK_SIZE = 0x1000;

        uint64_t ref_klass = m_driver.read<uint64_t>(m_pid,
            m_ga_base + offsets::ga::ALL_PLAYERS_CLASS_SLOT);
        uint64_t heap_lo = 0x100000000ull;
        uint64_t heap_hi = 0x7FFFFFFFFFFFull;
        if (sane_heap_ptr(ref_klass)) {
            uint64_t rb = ref_klass & ~0xFFFFFFFFFull;
            heap_lo = (rb > 0x1000000000ull) ? rb - 0x1000000000ull : 0x100000000ull;
            heap_hi = rb + 0x2000000000ull;
        }

        std::vector<uint8_t> chunk(CHUNK_SIZE);
        std::unordered_set<uint64_t> seen;
        int checked = 0;

        for (uint64_t rva = SCAN_START; rva < SCAN_END; rva += CHUNK_SIZE) {
            if (!m_driver.read_memory(m_pid, m_ga_base + rva, chunk.data(), CHUNK_SIZE))
                continue;

            for (uint32_t off = 0; off < CHUNK_SIZE; off += 8) {
                uint64_t klass = *reinterpret_cast<uint64_t*>(&chunk[off]);
                if (klass < heap_lo || klass > heap_hi || (klass & 7)) continue;
                if (!seen.insert(klass).second) continue;

                uint64_t sf = m_driver.read<uint64_t>(m_pid,
                    klass + offsets::STATIC_FIELDS_OFFSET);
                if (!sane_heap_ptr(sf)) continue;

                checked++;

                for (int32_t so = 0; so <= 0x100; so += 8) {
                    uint64_t cand = m_driver.read<uint64_t>(m_pid, sf + so);
                    if (!sane_heap_ptr(cand)) continue;

                    int32_t size = m_driver.read<int32_t>(m_pid,
                        cand + offsets::list_t::SIZE);
                    if (size <= 0 || size > 64) continue;

                    uint64_t items = m_driver.read<uint64_t>(m_pid,
                        cand + offsets::list_t::ITEMS_ARRAY);
                    if (!sane_heap_ptr(items)) continue;

                    uint64_t first = m_driver.read<uint64_t>(m_pid,
                        items + offsets::array_t::FIRST_ELEMENT);
                    if (!sane_heap_ptr(first)) continue;

                    uint64_t fk = m_driver.read<uint64_t>(m_pid, first);
                    if (fk != m_pc_klass) continue;

                    uint64_t name_ptr = m_driver.read<uint64_t>(m_pid,
                        klass + offsets::il2cpp_class::NAME_PTR);
                    std::string name;
                    if (sane_ptr(name_ptr)) name = m_driver.read_string(m_pid, name_ptr, 48);

                    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::steady_clock::now() - t0).count();
                    printf("[+] PC list owner: %s  sfields=0x%llX  +0x%02X  size=%d  (%lld ms, %d classes checked)\n",
                           name.empty() ? "<unknown>" : name.c_str(),
                           (unsigned long long)sf, so, size, (long long)dt, checked);

                    m_pc_list_sfields = sf;
                    m_pc_list_offset = so;
                    return true;
                }
            }
        }

        auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - t0).count();
        printf("[!] No class owning List<PlayerController> found (%lld ms, %d classes checked)\n",
               (long long)dt, checked);
        return false;
    }

    int32_t probe_pc_list_offset() {
        uint64_t sfields = m_driver.read<uint64_t>(m_pid,
            m_pc_klass + offsets::STATIC_FIELDS_OFFSET);
        if (!sane_heap_ptr(sfields)) return -1;

        for (int32_t off = 0; off <= 0x200; off += 8) {
            uint64_t cand = m_driver.read<uint64_t>(m_pid, sfields + off);
            if (!sane_heap_ptr(cand)) continue;

            uint64_t items = m_driver.read<uint64_t>(m_pid,
                cand + offsets::list_t::ITEMS_ARRAY);
            int32_t size = m_driver.read<int32_t>(m_pid,
                cand + offsets::list_t::SIZE);

            if (size <= 0 || size > 64) continue;
            if (!sane_heap_ptr(items)) continue;

            uint64_t first_pc = m_driver.read<uint64_t>(m_pid,
                items + offsets::array_t::FIRST_ELEMENT);
            if (!sane_heap_ptr(first_pc)) continue;
            uint64_t klass_of = m_driver.read<uint64_t>(m_pid, first_pc);
            if (klass_of != m_pc_klass) continue;

            printf("[+] List<PlayerController> at sfields+0x%02X (size=%d)\n", off, size);
            return off;
        }
        return -1;
    }

    int32_t probe_lp_player_offset(uint64_t lp_inst, uint64_t list_ptr) {
        if (!sane_heap_ptr(lp_inst) || !sane_heap_ptr(list_ptr)) return -1;

        uint64_t items = m_driver.read<uint64_t>(m_pid,
            list_ptr + offsets::list_t::ITEMS_ARRAY);
        int32_t size = m_driver.read<int32_t>(m_pid,
            list_ptr + offsets::list_t::SIZE);
        if (!sane_heap_ptr(items) || size <= 0 || size > 64) return -1;

        std::vector<uint64_t> pcs(size, 0);
        m_driver.read_memory(m_pid,
            items + offsets::array_t::FIRST_ELEMENT,
            pcs.data(), size * sizeof(uint64_t));

        for (int32_t off = 0; off <= 0x180; off += 8) {
            uint64_t cand = m_driver.read<uint64_t>(m_pid, lp_inst + off);
            if (!sane_heap_ptr(cand)) continue;
            for (auto pc : pcs) {
                if (pc == cand) {
                    printf("[+] LocalPlayer.Player at instance+0x%02X\n", off);
                    return off;
                }
            }
        }
        return -1;
    }

    void scan_for_classes() {
        printf("[*] Scanning GameAssembly.dll for PlayerController & LocalPlayer classes...\n");

        auto t0 = std::chrono::steady_clock::now();

        uint64_t ref_klass = m_driver.read<uint64_t>(m_pid,
            m_ga_base + offsets::ga::ALL_PLAYERS_CLASS_SLOT);
        uint64_t heap_lo = 0x100000000ull;
        uint64_t heap_hi = 0x7FFFFFFFFFFFull;

        if (sane_heap_ptr(ref_klass)) {

            uint64_t ref_base = ref_klass & ~0xFFFFFFFFFull;
            heap_lo = (ref_base > 0x1000000000ull) ? ref_base - 0x1000000000ull : 0x100000000ull;
            heap_hi = ref_base + 0x2000000000ull;
            if (heap_hi > 0x7FFFFFFFFFFFull) heap_hi = 0x7FFFFFFFFFFFull;

        }

        const uint64_t SCAN_START = 0x4E00000;
        const uint64_t SCAN_END   = 0x5A00000;
        const uint32_t CHUNK_SIZE = 0x1000;

        std::vector<uint8_t> chunk(CHUNK_SIZE);
        int candidates = 0;

        for (uint64_t rva = SCAN_START; rva < SCAN_END; rva += CHUNK_SIZE) {
            if (m_pc_klass && m_lp_klass && m_lsh_klass) break;

            if (!m_driver.read_memory(m_pid, m_ga_base + rva, chunk.data(), CHUNK_SIZE))
                continue;

            for (uint32_t off = 0; off < CHUNK_SIZE; off += 8) {
                uint64_t val = *reinterpret_cast<uint64_t*>(&chunk[off]);

                if (val < heap_lo || val > heap_hi || (val & 7)) continue;

                candidates++;

                uint32_t isz = m_driver.read<uint32_t>(m_pid,
                    val + offsets::il2cpp_class::INSTANCE_SIZE);

                if (isz == offsets::player_controller::INSTANCE_SIZE && !m_pc_klass) {

                    uint64_t name_ptr = m_driver.read<uint64_t>(m_pid,
                        val + offsets::il2cpp_class::NAME_PTR);
                    if (!sane_ptr(name_ptr)) continue;

                    std::string name = m_driver.read_string(m_pid, name_ptr, 32);
                    if (name == "PlayerController") {
                        m_pc_klass = val;
                        printf("[+] PlayerController Class$$ = 0x%llX (slot RVA 0x%llX)\n",
                               (unsigned long long)val, (unsigned long long)(rva + off));
                    }
                }
                else if (isz == offsets::local_player::INSTANCE_SIZE_LP && !m_lp_klass) {
                    uint64_t name_ptr = m_driver.read<uint64_t>(m_pid,
                        val + offsets::il2cpp_class::NAME_PTR);
                    if (!sane_ptr(name_ptr)) continue;

                    std::string name = m_driver.read_string(m_pid, name_ptr, 32);
                    if (name == "LocalPlayer") {
                        m_lp_klass = val;
                        printf("[+] LocalPlayer Class$$ = 0x%llX (slot RVA 0x%llX)\n",
                               (unsigned long long)val, (unsigned long long)(rva + off));
                    }
                }
                else if (!m_lsh_klass && isz >= 0x300 && isz <= 0x800) {

                    uint64_t name_ptr = m_driver.read<uint64_t>(m_pid,
                        val + offsets::il2cpp_class::NAME_PTR);
                    if (!sane_ptr(name_ptr)) continue;
                    std::string name = m_driver.read_string(m_pid, name_ptr, 32);
                    if (name == "LobbySceneHandler") {
                        m_lsh_klass = val;
                        printf("[+] LobbySceneHandler Class$$ = 0x%llX (slot RVA 0x%llX)\n",
                               (unsigned long long)val,
                               (unsigned long long)(rva + off));
                    }
                }
            }
        }

        auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - t0).count();

        printf("[*] Class scan complete: %lld ms, %d candidates checked\n",
               (long long)dt, candidates);

        if (!m_pc_klass)
            printf("[!] PlayerController NOT FOUND - ESP will not show players\n");
        if (!m_lp_klass)
            printf("[!] LocalPlayer NOT FOUND - camera/local player ID unavailable\n");
        if (!m_lsh_klass)
            printf("[!] LobbySceneHandler NOT FOUND - auto map-detect disabled\n");

        if (!m_lsh_klass) {

            auto is_valid_klass_name = [](const std::string& n) {
                if (n.size() < 3 || n.size() > 64) return false;
                char c0 = n[0];
                if (!((c0 >= 'A' && c0 <= 'Z') || c0 == '_')) return false;
                for (char c : n) {
                    if (!(c == '_' || c == '.' || c == '`' ||
                          c == '<' || c == '>' || c == ',' ||
                          (c >= '0' && c <= '9') ||
                          (c >= 'A' && c <= 'Z') ||
                          (c >= 'a' && c <= 'z')))
                        return false;
                }
                return true;
            };

            printf("[*] LSH-finder: scanning every klass for sfields+0xC = [0..15], valid name\n");
            int hits = 0;
            for (uint64_t rva = SCAN_START; rva < SCAN_END; rva += CHUNK_SIZE) {
                if (!m_driver.read_memory(m_pid, m_ga_base + rva,
                                          chunk.data(), CHUNK_SIZE))
                    continue;
                for (uint32_t off = 0; off < CHUNK_SIZE; off += 8) {
                    uint64_t kv = *reinterpret_cast<uint64_t*>(&chunk[off]);
                    if (kv < heap_lo || kv > heap_hi || (kv & 7)) continue;

                    uint64_t sf = m_driver.read<uint64_t>(
                        m_pid, kv + offsets::il2cpp_class::STATIC_FIELDS);
                    if (!sane_heap_ptr(sf)) continue;
                    int32_t cval = m_driver.read<int32_t>(m_pid, sf + 0xC);
                    if (cval < 0 || cval > 15) continue;
                    uint8_t scene_byte = m_driver.read<uint8_t>(m_pid, sf + 0x8);
                    if (scene_byte > 1) continue;

                    uint64_t name_ptr = m_driver.read<uint64_t>(
                        m_pid, kv + offsets::il2cpp_class::NAME_PTR);
                    if (!sane_ptr(name_ptr)) continue;
                    std::string name = m_driver.read_string(m_pid, name_ptr, 64);
                    if (!is_valid_klass_name(name)) continue;

                    uint8_t sfbuf[0x20]{};
                    m_driver.read_memory(m_pid, sf, sfbuf, sizeof(sfbuf));

                    bool any_nz = false;
                    for (int i = 0; i < (int)sizeof(sfbuf); i++)
                        if (sfbuf[i]) { any_nz = true; break; }
                    if (!any_nz) continue;

                    if (++hits >= 80) {

                        rva = SCAN_END;
                        break;
                    }
                }
            }
            printf("[*] LSH-finder: %d candidate(s) ??pick the one whose sf+0x0C tracks your current map\n", hits);
        }

        m_class_scan_done = true;
    }

    int read_current_map() {
        if (!m_lsh_klass) return -1;
        uint64_t sfields = m_driver.read<uint64_t>(
            m_pid, m_lsh_klass + offsets::il2cpp_class::STATIC_FIELDS);
        if (!sane_ptr(sfields)) return -1;
        int32_t map_id = m_driver.read<int32_t>(m_pid, sfields + 0xC);
        if (map_id < 0 || map_id > 31) return -1;
        return map_id;
    }

    bool m_chain_dumped = false;
    bool m_dict_dumped = false;
    bool m_is_dictionary = false;

    uint64_t resolve_all_players_list() {

        if (!m_pc_klass) return 0;
        uint64_t klass = m_pc_klass;
        uint64_t sfields = m_driver.read<uint64_t>(m_pid,
            klass + offsets::STATIC_FIELDS_OFFSET);

        uint64_t coll_now = sane_heap_ptr(sfields)
            ? m_driver.read<uint64_t>(m_pid, sfields + 0x00) : 0;
        if (!m_chain_dumped && sane_heap_ptr(coll_now)) {
            m_chain_dumped = true;

            auto class_name = [&](uint64_t k) -> std::string {
                if (!sane_heap_ptr(k)) return "<bad>";
                uint64_t np = m_driver.read<uint64_t>(m_pid,
                    k + offsets::il2cpp_class::NAME_PTR);
                if (!sane_ptr(np)) return "<no name>";
                return m_driver.read_string(m_pid, np, 64);
            };

            if (m_pc_klass) {
                uint64_t pc_sf = m_driver.read<uint64_t>(m_pid,
                    m_pc_klass + offsets::STATIC_FIELDS_OFFSET);
                uint64_t coll = m_driver.read<uint64_t>(m_pid, pc_sf + 0x00);
                if (sane_heap_ptr(coll)) {
                    uint64_t coll_klass = m_driver.read<uint64_t>(m_pid, coll);
                    std::string cname = class_name(coll_klass);

                    if (cname.find("Dictionary") != std::string::npos) {
                        m_is_dictionary = true;
                        int32_t cnt = m_driver.read<int32_t>(m_pid,
                            coll + offsets::dict_t::COUNT);

                    } else if (cname.find("List") != std::string::npos) {
                        int32_t cnt = m_driver.read<int32_t>(m_pid,
                            coll + offsets::list_t::SIZE);

                    } else {

                        for (int i = 0; i < 8; i++) {
                            uint64_t v = m_driver.read<uint64_t>(m_pid, coll + i * 8);

                        }
                    }
                }
            }

            auto dump_sfields = [&](const char* label, uint64_t sf) {

                if (!sane_heap_ptr(sf)) return;
                for (int i = 0; i < 24; i++) {
                    uint64_t v = m_driver.read<uint64_t>(m_pid, sf + i * 8);
                    const char* tag = "";
                    char buf[128] = "";
                    if (sane_heap_ptr(v)) {
                        uint64_t items = m_driver.read<uint64_t>(m_pid, v + 0x10);
                        int32_t sz   = m_driver.read<int32_t>(m_pid, v + 0x18);
                        if (sane_heap_ptr(items) && sz >= 0 && sz <= 64) {

                            uint64_t fk = 0;
                            if (sz > 0) {
                                uint64_t first = m_driver.read<uint64_t>(m_pid,
                                    items + offsets::array_t::FIRST_ELEMENT);
                                if (sane_heap_ptr(first))
                                    fk = m_driver.read<uint64_t>(m_pid, first);
                            }
                            snprintf(buf, sizeof(buf),
                                "  <List size=%d items=0x%llX first_klass=0x%llX%s>",
                                sz, (unsigned long long)items, (unsigned long long)fk,
                                (fk == m_pc_klass && fk != 0) ? " == PC!" : "");
                            tag = buf;
                        }
                    }

                }
            };

            dump_sfields("PC klass", sfields);
        }

        if (!sane_heap_ptr(klass) || !sane_heap_ptr(sfields)) return 0;
        m_cached_all_players_sfields = sfields;

        uint64_t list_ptr = m_driver.read<uint64_t>(m_pid,
            sfields + offsets::ga::ALL_PLAYERS_FIELD_IN_SFIELDS);
        return sane_heap_ptr(list_ptr) ? list_ptr : 0;
    }

    uint64_t resolve_local_player() {

        if (!m_lp_klass) return 0;
        uint64_t sfields = m_driver.read<uint64_t>(m_pid,
            m_lp_klass + offsets::STATIC_FIELDS_OFFSET);
        if (!sane_heap_ptr(sfields)) return 0;
        m_cached_local_player_sfields = sfields;

        uint64_t lp_instance = m_driver.read<uint64_t>(m_pid,
            sfields + offsets::ga::LOCAL_PLAYER_INSTANCE_OFFSET);
        return sane_heap_ptr(lp_instance) ? lp_instance : 0;
    }

    uint64_t resolve_local_pc(uint64_t lp_inst, uint64_t list_ptr) {
        if (!sane_heap_ptr(lp_inst)) return 0;
        uint64_t pc = m_driver.read<uint64_t>(m_pid,
            lp_inst + offsets::local_player::PLAYER);
        if (sane_heap_ptr(pc)) return pc;

        if (m_lp_player_offset < 0) {
            m_lp_player_offset = probe_lp_player_offset(lp_inst, list_ptr);
            if (m_lp_player_offset < 0) return 0;
        }
        pc = m_driver.read<uint64_t>(m_pid, lp_inst + m_lp_player_offset);
        return sane_heap_ptr(pc) ? pc : 0;
    }

    int32_t read_game_state() {
        return m_driver.read<int32_t>(m_pid,
            m_ga_base + offsets::ga::GAME_STATE_SLOT);
    }

    PlayerData read_player(uint64_t pc, const CameraData& cam, bool is_local) {
        PlayerData p;
        p.pc_ptr = pc;
        p.is_local = is_local;

        uint8_t net_block[104]{};
        m_driver.read_memory(m_pid, pc + 0x338, net_block, sizeof(net_block));

        auto field = [&](int32_t off) -> const uint8_t* {
            return &net_block[off - 0x338];
        };

        p.actor_number    = *reinterpret_cast<const int32_t*>(field(offsets::player_controller::ACTOR_NUMBER));
        p.ready_state     = *reinterpret_cast<const int32_t*>(field(offsets::player_controller::READY_STATE));
        p.is_transmitting = *field(offsets::player_controller::IS_TRANSMITTING) != 0;
        p.mic_muted       = *field(offsets::player_controller::MIC_MUTED) != 0;
        p.no_mic_mode     = *field(offsets::player_controller::NO_MIC_MODE) != 0;
        p.disconnected    = *field(offsets::player_controller::DISCONNECTED_FROM_VOICE) != 0;

        float pos[3];
        std::memcpy(pos, field(offsets::player_controller::OLD_TRANSFORM_POSITION), sizeof(pos));
        p.pos_x = pos[0];
        p.pos_y = pos[1];
        p.pos_z = pos[2];

        uint64_t nick_str = m_driver.read<uint64_t>(m_pid, pc + 0x90);
        if (sane_ptr(nick_str)) {
            p.name = read_il2cpp_string(nick_str);
        }
        if (p.name.empty()) {
            p.name = "Player_" + std::to_string(p.actor_number);
        }

        uint8_t entity_block[0xB0]{};
        m_driver.read_memory(m_pid, pc + 0x20, entity_block, sizeof(entity_block));

        p.is_dead     = entity_block[0x89 - 0x20] != 0;
        p.role        = static_cast<Role>(*(int32_t*)&entity_block[0x90 - 0x20]);
        p.is_impostor = (p.role == Role::Duck);

        p.kill_cooldown = m_driver.read<float>(m_pid, pc + 0x70);

        if (p.role != Role::Unknown) {
            p.is_impostor = is_impostor_role(p.role);
        }

        return p;
    }

    void worker() {
        bool did_diag = false;
        int frame_num = 0;

        while (m_running.load(std::memory_order_acquire)) {
            auto& cfg = Config::get();
            auto frame_start = std::chrono::steady_clock::now();

            if (!did_diag) {
                did_diag = true;
                if (!m_class_scan_done)
                    scan_for_classes();

                if (m_pc_klass) {
                    uint64_t sf = m_driver.read<uint64_t>(m_pid, m_pc_klass + offsets::STATIC_FIELDS_OFFSET);

                    if (sane_heap_ptr(sf)) {
                        uint64_t lp = m_driver.read<uint64_t>(m_pid, sf + 0x00);

                        if (sane_heap_ptr(lp)) {
                            uint64_t items = m_driver.read<uint64_t>(m_pid, lp + 0x10);
                            int32_t count = m_driver.read<int32_t>(m_pid, lp + 0x18);

                        }
                    }
                }
                if (m_lp_klass) {
                    uint64_t sf = m_driver.read<uint64_t>(m_pid, m_lp_klass + offsets::STATIC_FIELDS_OFFSET);

                    if (sane_heap_ptr(sf)) {
                        uint64_t inst = m_driver.read<uint64_t>(m_pid, sf + 0x10);

                        if (sane_heap_ptr(inst)) {
                            uint64_t pc = m_driver.read<uint64_t>(m_pid, inst + offsets::local_player::PLAYER);

                        }
                    }
                }
            }

            frame_num++;

            GameSnapshot snap;
            snap.ga_base = m_ga_base;
            snap.pid = m_pid;
            snap.timestamp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now().time_since_epoch()).count();

            snap.game_state = read_game_state();
            snap.in_game = (snap.game_state >= 1);
            snap.current_map = read_current_map();
            if (frame_num <= 3 || frame_num % 500 == 0) {

            }
            snap.in_meeting = (snap.game_state == 2);

            uint64_t list_ptr = resolve_all_players_list();
            if (!list_ptr) {
                m_fail_count++;
                if (m_fail_count <= 3 || m_fail_count % 50 == 0) {

                }

                if (m_fail_count >= 15) {
                    m_state.push(std::move(snap));
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                continue;
            }
            m_fail_count = 0;

            uint64_t items = 0;
            int32_t count = 0;
            if (m_is_dictionary) {
                items = m_driver.read<uint64_t>(m_pid,
                    list_ptr + offsets::dict_t::ENTRIES);
                count = m_driver.read<int32_t>(m_pid,
                    list_ptr + offsets::dict_t::COUNT);
            } else {
                items = m_driver.read<uint64_t>(m_pid,
                    list_ptr + offsets::list_t::ITEMS_ARRAY);
                count = m_driver.read<int32_t>(m_pid,
                    list_ptr + offsets::list_t::SIZE);
            }

            if (frame_num <= 3 || frame_num % 100 == 0) {

            }

            if (!sane_ptr(items) || count < 0 || count > 64) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                m_state.push(std::move(snap));
                continue;
            }

            uint64_t local_player_inst = resolve_local_player();
            uint64_t local_pc = resolve_local_pc(local_player_inst, list_ptr);

            if (sane_ptr(local_player_inst)) {

                if (sane_ptr(local_pc)) {
                    float cam_pos[3]{};
                    m_driver.read_memory(m_pid,
                        local_pc + offsets::player_controller::OLD_TRANSFORM_POSITION,
                        cam_pos, sizeof(cam_pos));
                    snap.camera.pos_x = cam_pos[0];
                    snap.camera.pos_y = cam_pos[1];
                    snap.camera.pos_z = cam_pos[2];
                }

                uint64_t cam_ptr = m_driver.read<uint64_t>(m_pid,
                    local_player_inst + offsets::local_player::MAIN_CAMERA);
                if (sane_ptr(cam_ptr)) {

                    uint64_t native_cam = m_driver.read<uint64_t>(m_pid, cam_ptr + 0x10);
                    if (sane_ptr(native_cam)) {

                        float ortho = m_driver.read<float>(m_pid, native_cam + 0x38);
                        if (ortho > 0.5f && ortho < 50.f) {
                            snap.camera.ortho_size = ortho;
                        }
                    }
                }

                uint8_t lp_state = m_driver.read<uint8_t>(m_pid,
                    local_player_inst + offsets::local_player::IN_VOTING_SCREEN);
                snap.in_meeting = snap.in_meeting || (lp_state != 0);
            }

            int n = (count < cfg.max_cached_players) ? count : cfg.max_cached_players;
            std::vector<uint64_t> pc_ptrs(n, 0);
            if (n > 0) {
                if (m_is_dictionary) {

                    constexpr int MAX_STRIDE = 0x20;
                    std::vector<uint8_t> blk(n * MAX_STRIDE);
                    m_driver.read_memory(m_pid,
                        items + offsets::array_t::FIRST_ELEMENT,
                        blk.data(), blk.size());

                    if (!m_dict_dumped) {
                        m_dict_dumped = true;
                        int dump_n = n < 6 ? n : 6;

                        for (int i = 0; i < dump_n; i++) {

                            for (int b = 0; b < MAX_STRIDE; b++) {
                                printf(" %02X", blk[i * MAX_STRIDE + b]);
                                if (b == 7 || b == 15) printf(" |");
                            }
                            printf("\n");
                        }
                    }

                    int stride = offsets::dict_t::ENTRY_STRIDE;
                    int value_off = offsets::dict_t::ENTRY_VALUE_OFF;
                    int live = 0;
                    for (int i = 0; i < n; i++) {
                        int32_t hash = *reinterpret_cast<int32_t*>(
                            &blk[i * stride]);
                        if (hash < 0) continue;
                        uint64_t v = *reinterpret_cast<uint64_t*>(
                            &blk[i * stride + value_off]);
                        if (sane_heap_ptr(v)) { pc_ptrs[i] = v; live++; }
                    }
                    if (frame_num <= 3) {

                    }
                } else {

                    m_driver.read_memory(m_pid,
                        items + offsets::array_t::FIRST_ELEMENT,
                        pc_ptrs.data(),
                        n * sizeof(uint64_t));
                }
            }

            if (!sane_ptr(local_pc) && m_pc_is_local_off < 0 && n >= 3
                && m_pc_local_probe_attempts < 30) {
                m_pc_local_probe_attempts++;
                constexpr int SCAN_BEG = 0x20;
                constexpr int SCAN_END = 0x338;
                constexpr int SCAN_LEN = SCAN_END - SCAN_BEG;
                std::vector<std::vector<uint8_t>> blocks(n);
                int valid = 0;
                for (int i = 0; i < n; i++) {
                    if (!sane_ptr(pc_ptrs[i])) continue;
                    blocks[i].resize(SCAN_LEN);
                    m_driver.read_memory(m_pid, pc_ptrs[i] + SCAN_BEG,
                                         blocks[i].data(), SCAN_LEN);
                    valid++;
                }
                std::vector<int> candidates;
                if (valid >= 3) {
                    for (int rel = 0; rel < SCAN_LEN; rel++) {
                        int ones = 0, others = 0;
                        for (int i = 0; i < n; i++) {
                            if (blocks[i].empty()) continue;
                            uint8_t b = blocks[i][rel];
                            if (b == 1) ones++;
                            else if (b != 0) others++;
                        }
                        if (ones == 1 && others == 0)
                            candidates.push_back(SCAN_BEG + rel);
                    }
                }
                if (frame_num <= 3 || (frame_num % 100 == 0)) {

                    int dump = (int)candidates.size();
                    if (dump > 8) dump = 8;
                    for (int k = 0; k < dump; k++) {
                        int off = candidates[k];
                        int rel = off - SCAN_BEG;

                        int actor = -1;
                        uint64_t hot_pc = 0;
                        for (int i = 0; i < n; i++) {
                            if (blocks[i].empty()) continue;
                            if (blocks[i][rel] == 1) {
                                hot_pc = pc_ptrs[i];
                                actor = m_driver.read<int32_t>(m_pid,
                                    pc_ptrs[i] + offsets::player_controller::ACTOR_NUMBER);
                                break;
                            }
                        }

                    }
                }

                for (int off : candidates) {
                    if (off == 0x98) {
                        m_pc_is_local_off = 0x98;
                        printf("[+] PlayerController.isLocal at +0x98 (known-good shortcut, %zu candidates)\n",
                               candidates.size());
                        break;
                    }
                }

                if (m_pc_is_local_off < 0 && !candidates.empty()) {
                    std::unordered_map<uint64_t, int> votes;
                    std::unordered_map<uint64_t, int> best_off;
                    for (int off : candidates) {
                        int rel = off - SCAN_BEG;
                        for (int i = 0; i < n; i++) {
                            if (blocks[i].empty()) continue;
                            if (blocks[i][rel] == 1) {
                                uint64_t pc = pc_ptrs[i];
                                votes[pc]++;
                                if (off >= 0x80 && off > best_off[pc])
                                    best_off[pc] = off;
                                break;
                            }
                        }
                    }
                    uint64_t winner = 0;
                    int top = 0, second = 0;
                    for (auto& kv : votes) {
                        if (kv.second > top) { second = top; top = kv.second; winner = kv.first; }
                        else if (kv.second > second) second = kv.second;
                    }
                    if (top >= 2 && top > second && best_off[winner] >= 0x80) {
                        m_pc_is_local_off = best_off[winner];
                        printf("[+] PlayerController.isLocal at +0x%X (majority %d/%d votes from %zu candidates, winner pc=0x%llX)\n",
                               m_pc_is_local_off, top, (int)candidates.size(),
                               candidates.size(), (unsigned long long)winner);
                    }
                }

            }
            if (!sane_ptr(local_pc) && m_pc_is_local_off >= 0) {
                for (int i = 0; i < n; i++) {
                    if (!sane_ptr(pc_ptrs[i])) continue;
                    if (m_driver.read<uint8_t>(m_pid,
                            pc_ptrs[i] + m_pc_is_local_off) == 1) {
                        local_pc = pc_ptrs[i];
                        if (frame_num <= 3 || frame_num % 100 == 0) {

                        }
                        break;
                    }
                }
            }

            if (!sane_ptr(local_pc) && sane_ptr(local_player_inst)
                && m_lp_player_offset < 0) {
                for (int32_t off = 0; off <= 0x180; off += 8) {
                    uint64_t cand = m_driver.read<uint64_t>(m_pid,
                        local_player_inst + off);
                    if (!sane_heap_ptr(cand)) continue;
                    for (auto pc : pc_ptrs) {
                        if (pc && pc == cand) {
                            m_lp_player_offset = off;
                            local_pc = cand;
                            printf("[+] LocalPlayer.Player resolved at instance+0x%02X\n", off);
                            break;
                        }
                    }
                    if (m_lp_player_offset >= 0) break;
                }
            }

            if (sane_ptr(local_pc) && snap.camera.pos_x == 0.f
                                   && snap.camera.pos_y == 0.f) {
                float cam_pos[3]{};
                m_driver.read_memory(m_pid,
                    local_pc + offsets::player_controller::OLD_TRANSFORM_POSITION,
                    cam_pos, sizeof(cam_pos));
                snap.camera.pos_x = cam_pos[0];
                snap.camera.pos_y = cam_pos[1];
                snap.camera.pos_z = cam_pos[2];
            }

            snap.players.reserve(n);
            for (int i = 0; i < n; i++) {
                uint64_t pc = pc_ptrs[i];
                if (!sane_ptr(pc)) continue;

                bool is_local = (pc == local_pc);
                PlayerData pd = read_player(pc, snap.camera, is_local);

                if (is_local) {
                    snap.local_player_index = static_cast<int32_t>(snap.players.size());
                }

                if (sane_ptr(local_pc) && !is_local) {
                    float dx = pd.pos_x - snap.camera.pos_x;
                    float dy = pd.pos_y - snap.camera.pos_y;
                    pd.distance = std::sqrt(dx * dx + dy * dy);
                }

                snap.players.push_back(std::move(pd));
            }

            if (snap.camera.pos_x == 0.f && snap.camera.pos_y == 0.f && !snap.players.empty()) {
                int cam_idx = (snap.local_player_index >= 0) ? snap.local_player_index : 0;
                snap.camera.pos_x = snap.players[cam_idx].pos_x;
                snap.camera.pos_y = snap.players[cam_idx].pos_y;
                snap.camera.pos_z = snap.players[cam_idx].pos_z;
            }

            m_state.push(std::move(snap));

            auto elapsed = std::chrono::steady_clock::now() - frame_start;
            auto target = std::chrono::milliseconds(cfg.read_interval_ms);
            if (elapsed < target) {
                std::this_thread::sleep_for(target - elapsed);
            }
        }
    }
};

}
