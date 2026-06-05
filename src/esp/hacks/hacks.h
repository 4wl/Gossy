#pragma once

#include <cstdint>
#include <cstring>
#include <cstdio>
#include "driver_comm.h"

namespace esp {

namespace hacks {

constexpr int32_t LP_SF_INSTANCE      = 0x10;
constexpr int32_t LP_SF_PLAYER        = 0x18;
constexpr int32_t LP_SF_BASE_SPEED    = 0x24;
constexpr int32_t LP_SF_MOVE_SPEED    = 0x28;
constexpr int32_t LP_INST_FOGOFWAR    = 0x20;

inline int32_t encrypt_obscured(int32_t crypto_key, float value) {
    uint32_t v;
    std::memcpy(&v, &value, 4);
    v ^= static_cast<uint32_t>(crypto_key);
    uint8_t b[4];
    std::memcpy(b, &v, 4);

    uint8_t t = b[1];
    b[1] = b[2];
    b[2] = t;
    int32_t out;
    std::memcpy(&out, b, 4);
    return out;
}

inline float decrypt_obscured(int32_t crypto_key, int32_t hidden) {
    uint8_t b[4];
    std::memcpy(b, &hidden, 4);
    uint8_t t = b[1]; b[1] = b[2]; b[2] = t;
    uint32_t v;
    std::memcpy(&v, b, 4);
    v ^= static_cast<uint32_t>(crypto_key);
    float out;
    std::memcpy(&out, &v, 4);
    return out;
}

inline uint64_t lp_sfields(DriverComm& drv, uint32_t pid, uint64_t lp_klass) {
    if (!lp_klass) return 0;
    return drv.read<uint64_t>(pid, lp_klass + 0xB8  );
}

inline bool set_movement_speed(DriverComm& drv, uint32_t pid,
                               uint64_t lp_klass, float target_speed) {
    uint64_t sf = lp_sfields(drv, pid, lp_klass);
    if (!sf) return false;
    uint64_t obs_addr = sf + LP_SF_MOVE_SPEED;

    struct ObscuredFloat {
        int32_t currentCryptoKey;
        int32_t hiddenValue;
        uint8_t hiddenValueOldByte4[4];
        uint8_t inited;
        uint8_t pad[3];
        float   fakeValue;
        uint8_t fakeValueActive;
        uint8_t pad2[3];
    } obs{};
    static_assert(sizeof(obs) >= 0x18, "ObscuredFloat layout");
    if (!drv.read_memory(pid, obs_addr, &obs, sizeof(obs))) return false;
    if (!obs.inited) return false;

    obs.hiddenValue = encrypt_obscured(obs.currentCryptoKey, target_speed);
    if (obs.fakeValueActive) obs.fakeValue = target_speed;

    return drv.write_memory(pid, obs_addr, &obs, sizeof(obs));
}

inline float get_movement_speed(DriverComm& drv, uint32_t pid,
                                uint64_t lp_klass) {
    uint64_t sf = lp_sfields(drv, pid, lp_klass);
    if (!sf) return -1.f;
    int32_t key    = drv.read<int32_t>(pid, sf + LP_SF_MOVE_SPEED);
    int32_t hidden = drv.read<int32_t>(pid, sf + LP_SF_MOVE_SPEED + 4);
    return decrypt_obscured(key, hidden);
}

inline float get_base_speed(DriverComm& drv, uint32_t pid, uint64_t lp_klass) {
    uint64_t sf = lp_sfields(drv, pid, lp_klass);
    if (!sf) return -1.f;
    return drv.read<float>(pid, sf + LP_SF_BASE_SPEED);
}

}
}
