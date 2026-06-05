#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <mutex>
#include "cooldown_hack.h"
#include "zoom_hack.h"

namespace esp {

struct Color4 {
    float r, g, b, a;
    Color4(float r_ = 1.f, float g_ = 1.f, float b_ = 1.f, float a_ = 1.f)
        : r(r_), g(g_), b(b_), a(a_) {}
};

struct Config {

    bool esp_enabled           = true;
    bool menu_visible          = true;

    bool show_boxes            = true;
    bool show_corner_boxes     = true;
    bool show_names            = true;
    bool show_roles            = true;
    bool show_distance         = true;
    bool show_health           = false;
    bool show_dead_players     = true;
    bool show_ghost_indicator  = true;

    Color4 color_impostor      = { 1.0f, 0.2f, 0.2f, 1.0f };
    Color4 color_crewmate      = { 0.2f, 1.0f, 0.4f, 1.0f };
    Color4 color_dead          = { 0.5f, 0.5f, 0.5f, 0.6f };
    Color4 color_local         = { 0.3f, 0.7f, 1.0f, 1.0f };
    Color4 color_neutral       = { 1.0f, 0.85f, 0.2f, 1.0f };
    Color4 color_unknown       = { 0.9f, 0.9f, 0.9f, 1.0f };

    bool show_kill_cooldown    = true;
    Color4 color_cooldown_text = { 1.0f, 0.6f, 0.0f, 1.0f };

    bool show_radar            = true;
    float radar_size           = 200.0f;
    float radar_range          = 30.0f;
    float radar_x              = 20.0f;
    float radar_y              = 20.0f;
    float radar_opacity        = 0.75f;

    bool  speed_hack_enabled   = false;
    float speed_hack_value     = 5.0f;

    esp::cooldown::CooldownConfig cooldown_hack;

    esp::zoom::ZoomConfig zoom_hack;

    bool show_minimap          = true;
    bool minimap_auto_detect   = true;
    int   minimap_selected     = 0;
    float minimap_size_px      = 320.f;

    bool show_local_info       = true;
    bool show_meeting_timer    = true;
    bool show_sabotage_status  = true;
    bool show_door_status      = true;
    bool show_task_progress    = false;

    float box_thickness        = 1.5f;
    float font_size            = 13.0f;
    float max_draw_distance    = 100.0f;
    int   overlay_fps_cap      = 60;

    int   read_interval_ms     = 33;
    int   max_cached_players   = 32;
    bool  cache_positions      = true;

    int   toggle_esp_key       = VK_INSERT;
    int   toggle_menu_key      = VK_HOME;
    int   toggle_radar_key     = VK_END;

    static Config& get() {
        static Config instance;
        return instance;
    }

    std::mutex mtx;

private:
    Config() = default;
};

}
