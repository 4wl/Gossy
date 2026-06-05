#pragma once

#include <cstdint>
#include <cstdio>
#include "driver_comm.h"

namespace esp {
namespace zoom {

struct ZoomConfig {
    bool  enabled      = false;
    float target_ortho = 16.0f;
};

struct ZoomState {
    float    last_applied   = 0.0f;
    uint64_t last_write_tick = 0;
    bool     logged_first    = false;
    bool     fast_mode       = true;
};

namespace detail { inline bool is_heap_ptr(uint64_t p) {
    return p >= 0x10000000000ull && p < 0x7FFFFFFFFFFFull && (p & 7) == 0;
} }

namespace detail {
constexpr int32_t LP_CINEMACHINE_SDC = 0x68;
constexpr int32_t LP_CINEMACHINE_VC  = 0x70;
constexpr int32_t LP_MAIN_CAMERA     = 0x78;
constexpr int32_t CAMERA_NATIVE_PTR  = 0x10;
constexpr int32_t NATIVE_ORTHO_SIZE  = 0x38;
constexpr int32_t CVC_ORTHO_SIZE     = 0xB4;
constexpr int32_t CSDC_ANIM_TARGET   = 0xB8;
}

inline int apply(DriverComm& drv, uint32_t pid, uint64_t lp_instance,
                 const ZoomConfig& cfg, ZoomState& state)
{
    if (!cfg.enabled || !lp_instance) {
        state.last_applied = 0.0f;
        return 0;
    }

    uint64_t now = GetTickCount64();
    bool value_changed = cfg.target_ortho != state.last_applied;

    uint64_t interval = state.fast_mode ? 0ull : 250ull;
    if (!value_changed && now - state.last_write_tick < interval) return 0;
    state.last_write_tick = now;
    state.last_applied = cfg.target_ortho;

    float v = cfg.target_ortho;

    uint64_t cam_cs = drv.read<uint64_t>(pid, lp_instance + detail::LP_MAIN_CAMERA);
    if (!detail::is_heap_ptr(cam_cs)) {
        if (!state.logged_first) {
            state.logged_first = true;
            printf("[!] Zoom: LP+0x78 = 0x%llX is not a heap pointer\n",
                   (unsigned long long)cam_cs);
        }
        return 0;
    }
    uint64_t cam_native = drv.read<uint64_t>(pid, cam_cs + detail::CAMERA_NATIVE_PTR);
    if (!detail::is_heap_ptr(cam_native)) {
        if (!state.logged_first) {
            state.logged_first = true;
            printf("[!] Zoom: Camera native ptr = 0x%llX is not a heap pointer\n",
                   (unsigned long long)cam_native);
        }
        return 0;
    }

    const uint64_t ortho_addr = cam_native + detail::NATIVE_ORTHO_SIZE;
    drv.write_memory(pid, ortho_addr, &v, sizeof(v));

    if (!state.logged_first) {
        state.logged_first = true;

        float readback = drv.read<float>(pid, ortho_addr);
        printf("[+] Zoom: wrote %.2f to 0x%llX, readback=%.2f%s\n",
               v, (unsigned long long)ortho_addr, readback,
               (readback == v) ? " OK" : " (immediate overwrite - enabling fast_mode)");
        if (readback != v) state.fast_mode = true;

        uint8_t buf[0x180] = {0};
        if (drv.read_memory(pid, lp_instance, buf, sizeof(buf))) {

            int found = 0;
            for (size_t off = 0; off + 8 <= sizeof(buf); off += 8) {
                uint64_t p;
                std::memcpy(&p, buf + off, 8);
                if (detail::is_heap_ptr(p)) {

                    if (++found > 24) {  break; }
                }
            }
        }
    }
    return 1;
}

}
}
