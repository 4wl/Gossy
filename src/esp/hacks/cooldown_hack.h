#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include "driver_comm.h"
#include "ggd_offsets.h"
#include "offsets.h"

namespace esp {
namespace cooldown {

struct CooldownConfig {
    bool enabled            = false;
    int  write_interval_ms  = 50;
};

struct CooldownState {
    uint64_t              ucb_klass        = 0;
    std::vector<uint64_t> instances;
    uint64_t              last_write_tick  = 0;
    uint64_t              last_validate_tick = 0;
    bool                  klass_resolved   = false;
    bool                  klass_failed     = false;

    uint64_t              scan_lo          = 0;
    uint64_t              scan_hi          = 0;
    uint64_t              scan_cur         = 0;
    bool                  scan_complete    = false;
};

namespace detail {

constexpr uint32_t UCB_INSTANCE_SIZE   = 0x150;
constexpr int32_t  UCB_INTERNAL_CD_OFF = 0xCC;
constexpr uint32_t MAX_INSTANCES       = 1024;
constexpr uint32_t MAX_WRITE_TARGETS   = 256;

inline uint64_t find_ucb_klass(DriverComm& drv, uint32_t pid, uint64_t ga_base, uint64_t heap_lo, uint64_t heap_hi) {
    const uint64_t SCAN_START = 0x4E00000;
    const uint64_t SCAN_END   = 0x5A00000;
    const uint32_t CHUNK_SIZE = 0x1000;
    std::vector<uint8_t> chunk(CHUNK_SIZE);

    for (uint64_t rva = SCAN_START; rva < SCAN_END; rva += CHUNK_SIZE) {
        if (!drv.read_memory(pid, ga_base + rva, chunk.data(), CHUNK_SIZE)) continue;
        for (uint32_t off = 0; off < CHUNK_SIZE; off += 8) {
            uint64_t val = *reinterpret_cast<uint64_t*>(&chunk[off]);
            if (val < heap_lo || val > heap_hi || (val & 7)) continue;

            uint32_t isz = drv.read<uint32_t>(pid, val + esp::offsets::il2cpp_class::INSTANCE_SIZE);
            if (isz != UCB_INSTANCE_SIZE) continue;

            uint64_t name_ptr = drv.read<uint64_t>(pid, val + esp::offsets::il2cpp_class::NAME_PTR);
            if (name_ptr < 0x10000 || name_ptr > 0x7FFFFFFFFFFFull) continue;
            std::string name = drv.read_string(pid, name_ptr, 32);
            if (name == "UICooldownButton") return val;
        }
    }
    return 0;
}

constexpr uint64_t SCAN_STEP_BYTES = 0x8000000ull;
constexpr uint32_t CHUNK_SIZE      = 0x10000;

inline int scan_ucb_slice(
    DriverComm& drv, uint32_t pid,
    uint64_t ucb_klass,
    uint64_t scan_from, uint64_t scan_to,
    std::vector<uint64_t>& out)
{
    std::vector<uint8_t> chunk(CHUNK_SIZE);
    int reads_ok = 0, reads_fail = 0, added = 0;

    for (uint64_t addr = scan_from; addr < scan_to && out.size() < MAX_INSTANCES; addr += CHUNK_SIZE) {
        if (!drv.read_memory(pid, addr, chunk.data(), CHUNK_SIZE)) { reads_fail++; continue; }
        reads_ok++;
        for (uint32_t off = 0; off + 8 <= CHUNK_SIZE; off += 8) {
            uint64_t k = *reinterpret_cast<uint64_t*>(&chunk[off]);
            if (k != ucb_klass) continue;
            out.push_back(addr + off);
            added++;
            if (out.size() >= MAX_INSTANCES) break;
        }
    }
    if (added > 0) {
        printf("[+] Cooldown: slice [0x%llX..0x%llX] +%d (total %zu, %d ok / %d fail)\n",
               (unsigned long long)scan_from, (unsigned long long)scan_to,
               added, out.size(), reads_ok, reads_fail);
    }
    return added;
}

inline bool instances_still_valid(
    DriverComm& drv, uint32_t pid,
    const std::vector<uint64_t>& instances, uint64_t ucb_klass)
{
    if (instances.empty()) return false;
    int sampled = 0, ok = 0;
    const int step = (instances.size() > 8) ? (int)instances.size() / 8 : 1;
    for (size_t i = 0; i < instances.size(); i += step) {
        uint64_t k = drv.read<uint64_t>(pid, instances[i]);
        sampled++;
        if (k == ucb_klass) ok++;
    }

    return ok * 2 >= sampled;
}

}

inline int apply_cooldown_acceleration(
    DriverComm& drv, uint32_t pid,
    uint64_t ga_base,
    uint64_t local_pc,
    const CooldownConfig& cfg,
    CooldownState& state)
{
    if (!cfg.enabled || !local_pc) return 0;
    if (state.klass_failed) return 0;

    if (!state.klass_resolved) {

        const uint64_t anchor = local_pc & ~0xFFFFFFFFFull;
        const uint64_t heap_lo = (anchor > 0x1000000000ull) ? anchor - 0x1000000000ull : 0x100000000ull;
        const uint64_t heap_hi = (anchor + 0x2000000000ull > 0x7FFFFFFFFFFFull)
                                     ? 0x7FFFFFFFFFFFull : anchor + 0x2000000000ull;
        state.ucb_klass = detail::find_ucb_klass(drv, pid, ga_base, heap_lo, heap_hi);
        state.klass_resolved = true;
        if (!state.ucb_klass) {
            printf("[!] Cooldown: UICooldownButton klass not found in GA data section\n");
            state.klass_failed = true;
            return 0;
        }
        printf("[+] Cooldown: UICooldownButton klass = 0x%llX\n",
               (unsigned long long)state.ucb_klass);
    }

    uint64_t now = GetTickCount64();

    if (state.scan_lo == 0) {
        constexpr uint64_t MARGIN = 0x20000000ull;
        uint64_t lo_anchor = (state.ucb_klass < local_pc) ? state.ucb_klass : local_pc;
        uint64_t hi_anchor = (state.ucb_klass > local_pc) ? state.ucb_klass : local_pc;
        state.scan_lo  = (lo_anchor > MARGIN) ? lo_anchor - MARGIN : 0x100000000ull;
        state.scan_hi  = hi_anchor + MARGIN;
        state.scan_cur = state.scan_lo;
        printf("[*] Cooldown: incremental scan [0x%llX..0x%llX] (%.1f GB) in %llu MB slices\n",
               (unsigned long long)state.scan_lo, (unsigned long long)state.scan_hi,
               (double)(state.scan_hi - state.scan_lo) / (double)(1ull << 30),
               (unsigned long long)(detail::SCAN_STEP_BYTES >> 20));
    }

    if (!state.scan_complete) {
        uint64_t slice_end = state.scan_cur + detail::SCAN_STEP_BYTES;
        if (slice_end > state.scan_hi) slice_end = state.scan_hi;
        detail::scan_ucb_slice(drv, pid, state.ucb_klass,
                               state.scan_cur, slice_end, state.instances);
        state.scan_cur = slice_end;
        if (state.scan_cur >= state.scan_hi) {
            state.scan_complete = true;

            auto dist = [local_pc](uint64_t a) {
                return (a > local_pc) ? (a - local_pc) : (local_pc - a);
            };
            std::sort(state.instances.begin(), state.instances.end(),
                      [&](uint64_t a, uint64_t b) { return dist(a) < dist(b); });
            if (state.instances.size() > detail::MAX_WRITE_TARGETS) {
                state.instances.resize(detail::MAX_WRITE_TARGETS);
            }
            printf("[+] Cooldown: scan complete, %zu write targets (closest to local_pc=0x%llX, nearest=0x%llX dist=%.1f MB, farthest=0x%llX dist=%.1f MB)\n",
                   state.instances.size(),
                   (unsigned long long)local_pc,
                   (unsigned long long)state.instances.front(),
                   (double)dist(state.instances.front()) / (1024.0*1024.0),
                   (unsigned long long)state.instances.back(),
                   (double)dist(state.instances.back()) / (1024.0*1024.0));
        }
    } else if (now - state.last_validate_tick >= 5000ull) {

        state.last_validate_tick = now;
        if (!detail::instances_still_valid(drv, pid, state.instances, state.ucb_klass)) {
            printf("[*] Cooldown: instances stale, restarting incremental scan\n");
            state.instances.clear();
            state.scan_cur = state.scan_lo;
            state.scan_complete = false;
        }
    }
    if (state.instances.empty()) return 0;

    uint64_t interval = (cfg.write_interval_ms > 0) ? (uint64_t)cfg.write_interval_ms : 50ull;
    if (now - state.last_write_tick < interval) return 0;
    state.last_write_tick = now;

    static bool dx_done = false;
    if (!dx_done) {
        dx_done = true;
        const size_t n = state.instances.size();
        int nonzero = 0;
        for (uint64_t inst : state.instances) {
            float v = drv.read<float>(pid, inst + detail::UCB_INTERNAL_CD_OFF);
            if (v > 0.001f && v < 1000.0f) nonzero++;
        }

        if (n > 0) {
            uint64_t inst0 = state.instances[0];
            float before = drv.read<float>(pid, inst0 + detail::UCB_INTERNAL_CD_OFF);
            float w = 0.0f;
            drv.write_memory(pid, inst0 + detail::UCB_INTERNAL_CD_OFF, &w, sizeof(w));
            float after = drv.read<float>(pid, inst0 + detail::UCB_INTERNAL_CD_OFF);

        }
    }

    float zero = 0.0f;
    for (uint64_t inst : state.instances) {
        drv.write_memory(pid, inst + (uint64_t)detail::UCB_INTERNAL_CD_OFF, &zero, sizeof(zero));
    }
    return (int)state.instances.size();
}

}
}
