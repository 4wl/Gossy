#pragma once

#include "renderer.h"
#include "game_data.h"
#include "config.h"

#include <cmath>
#include <cstdio>
#include <algorithm>

namespace esp {

class EspDraw {
public:
    EspDraw(Renderer& renderer) : m_renderer(renderer) {}

    void draw(const GameSnapshot& snap) {
        auto& cfg = Config::get();
        if (!cfg.esp_enabled) return;

        for (size_t i = 0; i < snap.players.size(); i++) {
            const auto& p = snap.players[i];
            draw_player(p, snap, cfg);
        }

        if (cfg.show_radar && snap.local_player_index >= 0) {
            draw_radar(snap, cfg);
        }

        if (cfg.show_local_info && snap.local_player_index >= 0) {
            draw_local_info(snap, cfg);
        }

        draw_status_bar(snap, cfg);
    }

private:
    Renderer& m_renderer;

    Color4 get_player_color(const PlayerData& p, const Config& cfg) {
        if (p.is_local) return cfg.color_local;
        if (p.is_dead || p.is_ghost) return cfg.color_dead;
        if (p.is_impostor || is_impostor_role(p.role)) return cfg.color_impostor;
        if (is_neutral_role(p.role)) return cfg.color_neutral;
        if (p.role != Role::Unknown) return cfg.color_crewmate;
        return cfg.color_unknown;
    }

    void draw_player(const PlayerData& p, const GameSnapshot& snap, const Config& cfg) {

        if ((p.is_dead || p.is_ghost) && !cfg.show_dead_players) return;

        if (!p.is_local && p.distance > cfg.max_draw_distance) return;

        float sx, sy;
        if (!m_renderer.world_to_screen(p.pos_x, p.pos_y, snap.camera, sx, sy))
            return;

        Color4 col = get_player_color(p, cfg);

        float scale = static_cast<float>(m_renderer.overlay()->height())
                    / (2.f * snap.camera.ortho_size);
        float box_w = 1.0f * scale;
        float box_h = 1.5f * scale;

        if (box_w < 12.f) box_w = 12.f;
        if (box_h < 18.f) box_h = 18.f;

        float box_x = sx - box_w * 0.5f;
        float box_y = sy - box_h * 0.5f;

        if (cfg.show_boxes) {
            if (cfg.show_corner_boxes) {
                m_renderer.draw_corner_box(box_x, box_y, box_w, box_h,
                    col, cfg.box_thickness);
            } else {
                m_renderer.draw_rect(box_x, box_y, box_w, box_h,
                    col, cfg.box_thickness);
            }
        }

        if ((p.is_dead || p.is_ghost) && cfg.show_ghost_indicator) {
            Color4 ghost_col = { 0.7f, 0.7f, 0.9f, 0.6f };
            m_renderer.draw_text(sx, box_y - 16.f, "[DEAD]", ghost_col, true, cfg.font_size - 2.f);
        }

        float text_y = box_y - 14.f;
        if (cfg.show_names && !p.name.empty()) {
            Color4 name_col = p.is_local ? cfg.color_local : Color4(1.f, 1.f, 1.f, 0.95f);
            m_renderer.draw_text(sx, text_y, p.name, name_col, true, cfg.font_size);
            text_y -= 14.f;
        }

        if (cfg.show_roles && p.role != Role::Unknown) {
            Color4 role_col = get_player_color(p, cfg);
            std::string role_str = "[";
            role_str += role_to_string(p.role);
            role_str += "]";
            m_renderer.draw_text(sx, box_y + box_h + 2.f, role_str, role_col, true, cfg.font_size - 1.f);
        }

        if (cfg.show_distance && !p.is_local) {
            char dist_buf[32];
            snprintf(dist_buf, sizeof(dist_buf), "%.1fm", p.distance);
            Color4 dist_col = { 0.8f, 0.8f, 0.8f, 0.8f };
            m_renderer.draw_text(sx, box_y + box_h + 16.f, dist_buf, dist_col, true, cfg.font_size - 2.f);
        }

        if (cfg.show_kill_cooldown && p.kill_cooldown > 0.1f && p.is_impostor) {
            char cd_buf[32];
            snprintf(cd_buf, sizeof(cd_buf), "CD: %.1fs", p.kill_cooldown);
            m_renderer.draw_text(sx, box_y + box_h + 30.f, cd_buf,
                cfg.color_cooldown_text, true, cfg.font_size - 1.f);
        }
    }

    void draw_radar(const GameSnapshot& snap, const Config& cfg) {
        float rx = cfg.radar_x;
        float ry = cfg.radar_y;
        float rs = cfg.radar_size;
        float range = cfg.radar_range;

        Color4 bg = { 0.05f, 0.05f, 0.08f, cfg.radar_opacity };
        m_renderer.draw_rect_filled(rx, ry, rs, rs, bg);

        Color4 border = { 0.3f, 0.3f, 0.5f, cfg.radar_opacity };
        m_renderer.draw_rect(rx, ry, rs, rs, border, 1.5f);

        Color4 cross = { 0.2f, 0.2f, 0.3f, cfg.radar_opacity * 0.5f };
        float cx = rx + rs * 0.5f;
        float cy = ry + rs * 0.5f;
        m_renderer.draw_line(cx, ry, cx, ry + rs, cross, 0.5f);
        m_renderer.draw_line(rx, cy, rx + rs, cy, cross, 0.5f);

        Color4 title_col = { 0.7f, 0.7f, 0.8f, cfg.radar_opacity };
        m_renderer.draw_text(cx, ry - 14.f, "RADAR", title_col, true, 11.f);

        if (snap.local_player_index < 0) return;
        const auto& local = snap.players[snap.local_player_index];

        for (size_t i = 0; i < snap.players.size(); i++) {
            const auto& p = snap.players[i];
            if (p.is_dead && !cfg.show_dead_players) continue;

            float dx = p.pos_x - local.pos_x;
            float dy = p.pos_y - local.pos_y;

            float radar_x = cx + (dx / range) * (rs * 0.5f);
            float radar_y = cy - (dy / range) * (rs * 0.5f);

            radar_x = std::clamp(radar_x, rx + 3.f, rx + rs - 3.f);
            radar_y = std::clamp(radar_y, ry + 3.f, ry + rs - 3.f);

            Color4 dot_col = get_player_color(p, cfg);
            float dot_r = p.is_local ? 4.f : 3.f;
            m_renderer.draw_circle_filled(radar_x, radar_y, dot_r, dot_col);
        }
    }

    void draw_local_info(const GameSnapshot& snap, const Config& cfg) {
        if (snap.local_player_index < 0) return;
        const auto& local = snap.players[snap.local_player_index];

        float panel_x = static_cast<float>(m_renderer.overlay()->width()) - 280.f;
        float panel_y = 20.f;
        float panel_w = 260.f;
        float line_h  = 16.f;

        Color4 bg = { 0.05f, 0.05f, 0.08f, 0.85f };
        m_renderer.draw_rect_filled(panel_x, panel_y, panel_w, 180.f, bg);
        Color4 border = { 0.3f, 0.25f, 0.5f, 0.6f };
        m_renderer.draw_rect(panel_x, panel_y, panel_w, 180.f, border, 1.f);

        float tx = panel_x + 10.f;
        float ty = panel_y + 8.f;
        Color4 label_col = { 0.6f, 0.6f, 0.7f, 1.f };
        Color4 value_col = { 0.95f, 0.95f, 1.f, 1.f };

        m_renderer.draw_text(panel_x + panel_w * 0.5f, ty, "LOCAL PLAYER",
            { 0.5f, 0.4f, 1.f, 1.f }, true, 14.f);
        ty += line_h + 4.f;

        m_renderer.draw_text(tx, ty, "Name: " + local.name, value_col, false, 12.f);
        ty += line_h;

        std::string role_str = "Role: ";
        role_str += role_to_string(local.role);
        Color4 role_col = get_player_color(local, cfg);
        m_renderer.draw_text(tx, ty, role_str, role_col, false, 12.f);
        ty += line_h;

        char pos_buf[64];
        snprintf(pos_buf, sizeof(pos_buf), "Pos: %.1f, %.1f", local.pos_x, local.pos_y);
        m_renderer.draw_text(tx, ty, pos_buf, label_col, false, 12.f);
        ty += line_h;

        std::string status = "Status: ";
        if (local.is_dead)    status += "DEAD";
        else if (local.is_ghost) status += "GHOST";
        else                  status += "ALIVE";
        m_renderer.draw_text(tx, ty, status, value_col, false, 12.f);
        ty += line_h;

        int alive_count = 0;
        int dead_count = 0;
        for (const auto& p : snap.players) {
            if (p.is_dead || p.is_ghost) dead_count++;
            else alive_count++;
        }
        char count_buf[64];
        snprintf(count_buf, sizeof(count_buf), "Players: %d alive / %d dead",
            alive_count, dead_count);
        m_renderer.draw_text(tx, ty, count_buf, label_col, false, 12.f);
        ty += line_h;

        const char* state_str = "Unknown";
        if (snap.in_meeting) state_str = "MEETING";
        else if (snap.in_game) state_str = "IN GAME";
        else state_str = "LOBBY";
        m_renderer.draw_text(tx, ty, std::string("State: ") + state_str, value_col, false, 12.f);
        ty += line_h;

        if (local.is_impostor && local.kill_cooldown > 0.f) {
            char cd_buf[64];
            snprintf(cd_buf, sizeof(cd_buf), "Kill CD: %.1fs", local.kill_cooldown);
            m_renderer.draw_text(tx, ty, cd_buf, cfg.color_cooldown_text, false, 12.f);
        }
    }

    void draw_status_bar(const GameSnapshot& snap, const Config& cfg) {
        float scr_w = static_cast<float>(m_renderer.overlay()->width());

        if (cfg.show_sabotage_status && snap.sabotage.is_active) {
            char sabo_buf[64];
            snprintf(sabo_buf, sizeof(sabo_buf), "SABOTAGE ACTIVE (%.1fs)",
                snap.sabotage.remaining_time);
            Color4 sabo_col = { 1.f, 0.3f, 0.1f, 1.f };
            m_renderer.draw_text(scr_w * 0.5f, 5.f, sabo_buf, sabo_col, true, 16.f);
        }

        if (cfg.show_door_status && snap.doors.doors_closed) {
            Color4 door_col = { 1.f, 0.6f, 0.1f, 1.f };
            m_renderer.draw_text(scr_w * 0.5f, 25.f, "DOORS LOCKED", door_col, true, 14.f);
        }

        if (cfg.show_meeting_timer && snap.in_meeting) {
            Color4 meet_col = { 0.3f, 0.8f, 1.f, 1.f };
            m_renderer.draw_text(scr_w * 0.5f, 45.f, "MEETING IN PROGRESS",
                meet_col, true, 16.f);
        }
    }
};

}
