#pragma once

#include "driver_comm.h"
#include <string>
#include <vector>
#include <optional>
#include <cstdio>

struct ModuleInfo {
    std::wstring name;
    uint64_t     base;
    uint32_t     size;
};

#pragma pack(push, 1)
struct DosHeader {
    uint16_t e_magic;
    uint8_t  pad[58];
    int32_t  e_lfanew;
};

struct NtHeaders64 {
    uint32_t Signature;
    uint8_t  FileHeader[20];

    uint16_t Magic;
    uint8_t  pad[6];
    uint64_t ImageBase_oh;
    uint32_t SectionAlignment;
    uint32_t FileAlignment;
    uint8_t  pad2[16];
    uint32_t SizeOfImage;

};
#pragma pack(pop)

class ModuleResolver {
public:
    ModuleResolver(DriverComm& driver, uint32_t pid)
        : m_driver(driver), m_pid(pid) {}

    bool init() {
        auto info = m_driver.query_process(m_pid);
        if (!info) return false;

        m_peb_addr = info->peb;
        m_process_base = info->base_address;
        m_cr3 = info->cr3;

        return m_peb_addr != 0;
    }

    bool refresh() {
        auto info = m_driver.query_process(m_pid);
        if (!info) return false;

        m_peb_addr = info->peb;
        m_process_base = info->base_address;
        m_cr3 = info->cr3;

        return m_peb_addr != 0;
    }

    std::optional<ModuleInfo> find_module(const std::wstring& name) {
        auto modules = enumerate_modules();
        for (const auto& mod : modules) {
            if (_wcsicmp(mod.name.c_str(), name.c_str()) == 0) {
                return mod;
            }
        }
        return std::nullopt;
    }

    uint32_t get_module_size(uint64_t base) {
        DosHeader dos{};
        if (!m_driver.read_memory(m_pid, base, &dos, sizeof(dos)))
            return 0;

        if (dos.e_magic != 0x5A4D)
            return 0;

        NtHeaders64 nt{};
        if (!m_driver.read_memory(m_pid, base + dos.e_lfanew, &nt, sizeof(nt)))
            return 0;

        if (nt.Signature != 0x00004550)
            return 0;

        return nt.SizeOfImage;
    }

    std::vector<ModuleInfo> enumerate_modules() {
        std::vector<ModuleInfo> result;

        if (!m_peb_addr) return result;

        uint64_t ldr_ptr = 0;
        if (!m_driver.read_memory(m_pid, m_peb_addr + 0x18, &ldr_ptr, sizeof(ldr_ptr)))
            return result;

        if (!ldr_ptr) return result;

        uint64_t list_head = ldr_ptr + 0x20;
        uint64_t first_entry = 0;
        if (!m_driver.read_memory(m_pid, list_head, &first_entry, sizeof(first_entry)))
            return result;

        if (!first_entry || first_entry == list_head)
            return result;

        uint64_t current = first_entry;
        int count = 0;

        while (current != 0 && current != list_head && count < 500) {

            uint64_t entry_base = current - 0x10;

            uint64_t dll_base = 0;
            uint32_t size_of_image = 0;
            m_driver.read_memory(m_pid, entry_base + 0x30, &dll_base, sizeof(dll_base));
            m_driver.read_memory(m_pid, entry_base + 0x40, &size_of_image, sizeof(size_of_image));

            uint16_t name_len = 0;
            uint64_t name_buf = 0;
            m_driver.read_memory(m_pid, entry_base + 0x58, &name_len, sizeof(name_len));
            m_driver.read_memory(m_pid, entry_base + 0x60, &name_buf, sizeof(name_buf));

            if (dll_base && name_buf && name_len > 0 && name_len < 1024) {
                std::wstring mod_name = m_driver.read_wstring(m_pid, name_buf, name_len / 2);

                if (size_of_image == 0)
                    size_of_image = get_module_size(dll_base);

                if (!mod_name.empty())
                    result.push_back({ mod_name, dll_base, size_of_image });
            }

            uint64_t next = 0;
            if (!m_driver.read_memory(m_pid, current, &next, sizeof(next)))
                break;

            if (next == 0 || next == current)
                break;

            current = next;
            count++;
        }

        return result;
    }

    std::optional<ModuleInfo> find_game_assembly() {
        return find_module(L"GameAssembly.dll");
    }

    std::optional<ModuleInfo> find_unity_player() {
        return find_module(L"UnityPlayer.dll");
    }

    uint64_t peb()          const { return m_peb_addr; }
    uint64_t process_base() const { return m_process_base; }
    uint64_t cr3()          const { return m_cr3; }

private:
    DriverComm& m_driver;
    uint32_t    m_pid;
    uint64_t    m_peb_addr = 0;
    uint64_t    m_process_base = 0;
    uint64_t    m_cr3 = 0;
};
