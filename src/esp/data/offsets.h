#pragma once

#include "ggd_offsets.h"

#include <cstdint>

namespace esp::offsets {

namespace il2cpp_class {
    constexpr int32_t NAME_PTR        = 0x10;
    constexpr int32_t NAMESPACE_PTR   = 0x18;
    constexpr int32_t FIELDS_PTR      = 0x80;
    constexpr int32_t STATIC_FIELDS   = 0xB8;
    constexpr int32_t INSTANCE_SIZE   = 0xF8;
}
constexpr int32_t STATIC_FIELDS_OFFSET = il2cpp_class::STATIC_FIELDS;

namespace list_t {
    constexpr int32_t ITEMS_ARRAY = 0x10;
    constexpr int32_t SIZE        = 0x18;
}

namespace array_t {
    constexpr int32_t LENGTH        = 0x18;
    constexpr int32_t FIRST_ELEMENT = 0x20;
}

namespace dict_t {

    constexpr int32_t BUCKETS         = 0x10;
    constexpr int32_t ENTRIES         = 0x18;
    constexpr int32_t COUNT           = 0x20;
    constexpr int32_t FREE_LIST       = 0x24;
    constexpr int32_t FREE_COUNT      = 0x28;

    constexpr int32_t ENTRY_STRIDE    = 0x18;
    constexpr int32_t ENTRY_VALUE_OFF = 0x10;
}

namespace il2cpp_string {
    constexpr int32_t LENGTH = 0x10;
    constexpr int32_t CHARS  = 0x14;
}

namespace ga {

    constexpr uint64_t ALL_PLAYERS_CLASS_SLOT  = ggd::rva::AllPlayers_Static;
    constexpr uint64_t LOCAL_PLAYER_CLASS_SLOT = ggd::rva::LocalPlayer_Static;
    constexpr uint64_t GAME_STATE_SLOT         = ggd::rva::GameState;
    constexpr uint64_t CAMERA_MAIN_RVA         = ggd::rva::Camera__Main;
    constexpr uint64_t GFX_DEVICE_RVA          = ggd::rva::GfxDevice;

    constexpr uint64_t ALL_PLAYERS_FIELD_IN_SFIELDS =
        ggd::PlayerController::PlayerControllers;

    constexpr uint64_t LOCAL_PLAYER_INSTANCE_OFFSET = 0x10;
}

namespace player_controller {
    constexpr int32_t ROOM_COLLIDER             = ggd::PlayerController::roomCollider;
    constexpr int32_t IS_TRANSMITTING           = ggd::PlayerController::isTransmitting;
    constexpr int32_t NO_MIC_MODE               = ggd::PlayerController::noMicMode;
    constexpr int32_t DISCONNECTED_FROM_VOICE   = ggd::PlayerController::disconnectedFromVoice;
    constexpr int32_t MIC_MUTED                 = ggd::PlayerController::micMuted;
    constexpr int32_t ACTOR_NUMBER              = ggd::PlayerController::actorNumber;
    constexpr int32_t READY_STATE               = ggd::PlayerController::readyState;
    constexpr int32_t OLD_TRANSFORM_POSITION    = ggd::PlayerController::oldTransformPosition;
    constexpr uint32_t INSTANCE_SIZE            = ggd::PlayerController::InstanceSize;
}

namespace local_player {
    constexpr uint32_t INSTANCE_SIZE_LP   = 0x180;
    constexpr int32_t INSTANCE             = 0x10;
    constexpr int32_t PLAYER               = 0x18;
    constexpr int32_t MAIN_CAMERA          = 0x78;
    constexpr int32_t IN_VOTING_SCREEN     = 0xBB;
    constexpr int32_t IS_GHOST             = 0x58;
}

namespace rva {
    constexpr uint64_t POSITION_FUNC      = ggd::rva::PlayerController__Position;
    constexpr uint64_t ROLE_CHECK_FUNC    = ggd::rva::PlayerController__Role;
    constexpr uint64_t IS_DEAD_FUNC       = ggd::rva::PlayerController__IsDead;
    constexpr uint64_t KILL_COOLDOWN_FUNC = ggd::rva::PlayerController__KillCooldown;
    constexpr uint64_t VELOCITY_FUNC      = ggd::rva::PlayerController__Velocity;
    constexpr uint64_t IS_IMPOSTOR_FUNC   = ggd::rva::PlayerController__IsImpostor;
    constexpr uint64_t PLAYER_NAME_FUNC   = ggd::rva::PlayerController__PlayerName;
    constexpr uint64_t PLAYER_ID_FUNC     = ggd::rva::PlayerController__PlayerId;
}

}
