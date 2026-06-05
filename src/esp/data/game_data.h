#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include <atomic>
#include <mutex>

namespace esp {

enum class Role : int32_t {
    Unknown        = -1,
    Goose          = 0,
    Duck           = 1,

    Sheriff         = 2,
    Engineer        = 3,
    Vigilante       = 4,
    Dodo           = 5,
    Pigeon         = 6,
    Falcon         = 7,
    Vulture        = 8,
    Pelican        = 9,
    Canadian       = 10,
    Morphling      = 11,
    Silencer       = 12,
    Professional   = 13,
    Spy            = 14,
    Snitch         = 15,
    Mechanic       = 16,
    Birdwatcher    = 17,
    Medium         = 18,
    Avenger        = 19,
    Lover          = 20,
    Dueling        = 21,
    Assassin       = 22,
    Undertaker     = 23,
    Cannibal       = 24,
    Locksmith      = 25,
    Identity       = 26,
    Bodyguard      = 27,
    Ninja          = 28,
    Detective      = 29,
    Adventurer     = 30,
    Technician     = 31,

};

inline const char* role_to_string(Role r) {
    switch (r) {
    case Role::Goose:        return "Goose";
    case Role::Duck:         return "Duck";
    case Role::Sheriff:      return "Sheriff";
    case Role::Engineer:     return "Engineer";
    case Role::Vigilante:    return "Vigilante";
    case Role::Dodo:         return "Dodo";
    case Role::Pigeon:       return "Pigeon";
    case Role::Falcon:       return "Falcon";
    case Role::Vulture:      return "Vulture";
    case Role::Pelican:      return "Pelican";
    case Role::Canadian:     return "Canadian";
    case Role::Morphling:    return "Morphling";
    case Role::Silencer:     return "Silencer";
    case Role::Professional: return "Professional";
    case Role::Spy:          return "Spy";
    case Role::Snitch:       return "Snitch";
    case Role::Mechanic:     return "Mechanic";
    case Role::Birdwatcher:  return "Birdwatcher";
    case Role::Medium:       return "Medium";
    case Role::Avenger:      return "Avenger";
    case Role::Lover:        return "Lover";
    case Role::Dueling:      return "Dueling";
    case Role::Assassin:     return "Assassin";
    case Role::Undertaker:   return "Undertaker";
    case Role::Cannibal:     return "Cannibal";
    case Role::Locksmith:    return "Locksmith";
    case Role::Identity:     return "Identity";
    case Role::Bodyguard:    return "Bodyguard";
    case Role::Ninja:        return "Ninja";
    case Role::Detective:    return "Detective";
    case Role::Adventurer:   return "Adventurer";
    case Role::Technician:   return "Technician";
    default:                 return "Unknown";
    }
}

inline bool is_impostor_role(Role r) {

    switch (r) {
    case Role::Duck:
    case Role::Morphling:
    case Role::Silencer:
    case Role::Professional:
    case Role::Spy:
    case Role::Assassin:
    case Role::Undertaker:
    case Role::Cannibal:
    case Role::Identity:
    case Role::Ninja:
        return true;
    default:
        return false;
    }
}

inline bool is_neutral_role(Role r) {
    switch (r) {
    case Role::Vulture:
    case Role::Pelican:
    case Role::Pigeon:
    case Role::Falcon:
    case Role::Dodo:
    case Role::Dueling:
    case Role::Lover:
        return true;
    default:
        return false;
    }
}

struct PlayerData {
    uint64_t pc_ptr           = 0;
    int32_t  actor_number     = -1;
    int32_t  ready_state      = 0;
    bool     is_transmitting  = false;
    bool     mic_muted        = false;
    bool     no_mic_mode      = false;
    bool     disconnected     = false;
    bool     is_dead          = false;
    bool     is_ghost         = false;
    bool     is_impostor      = false;
    Role     role             = Role::Unknown;
    float    pos_x            = 0.f;
    float    pos_y            = 0.f;
    float    pos_z            = 0.f;
    float    vel_x            = 0.f;
    float    vel_y            = 0.f;
    float    kill_cooldown    = 0.f;
    float    screen_x         = 0.f;
    float    screen_y         = 0.f;
    bool     on_screen        = false;
    float    distance         = 0.f;
    std::string name;
    bool     is_local         = false;
};

struct CameraData {
    float pos_x     = 0.f;
    float pos_y     = 0.f;
    float pos_z     = 0.f;
    float ortho_size = 5.f;
};

struct SabotageInfo {
    bool  is_active            = false;
    float remaining_time       = 0.f;
    int32_t active_count       = 0;
};

struct DoorState {
    bool  doors_closed         = false;
    float closing_time         = 0.f;
    float current_closing_time = 0.f;
};

struct GameSnapshot {

    std::vector<PlayerData> players;
    int32_t local_player_index = -1;

    CameraData camera;

    int32_t game_state        = 0;
    bool    in_meeting        = false;
    bool    in_game           = false;

    int32_t current_map       = -1;

    SabotageInfo sabotage;

    DoorState doors;

    uint64_t ga_base          = 0;
    uint32_t pid              = 0;
    int64_t  timestamp_ms     = 0;
};

class GameState {
public:
    void push(GameSnapshot&& snap) {
        std::lock_guard<std::mutex> lock(m_mtx);
        m_snapshot = std::move(snap);
        m_has_data.store(true, std::memory_order_release);
    }

    GameSnapshot get() const {
        std::lock_guard<std::mutex> lock(m_mtx);
        return m_snapshot;
    }

    bool has_data() const {
        return m_has_data.load(std::memory_order_acquire);
    }

private:
    mutable std::mutex m_mtx;
    GameSnapshot       m_snapshot;
    std::atomic<bool>  m_has_data{false};
};

}
