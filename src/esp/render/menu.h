#pragma once

#include "config.h"
#include "game_data.h"

#include <imgui.h>

namespace esp {

class Menu {
public:
    void draw(const GameSnapshot& snap) {
        auto& cfg = Config::get();

        if (!cfg.menu_visible) return;

        ImGui::SetNextWindowSize(ImVec2(420, 580), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);

        if (!ImGui::Begin("Goosssy ESP  [HOME to toggle]",
                          &cfg.menu_visible,
                          ImGuiWindowFlags_NoCollapse)) {
            ImGui::End();
            return;
        }

        if (ImGui::BeginTabBar("##tabs")) {

            if (ImGui::BeginTabItem("ESP")) {
                ImGui::Checkbox("Enable ESP", &cfg.esp_enabled);
                ImGui::Separator();

                ImGui::Text("Player Visuals");
                ImGui::Checkbox("Show Boxes", &cfg.show_boxes);
                ImGui::SameLine();
                ImGui::Checkbox("Corner Style", &cfg.show_corner_boxes);
                ImGui::Checkbox("Show Names", &cfg.show_names);
                ImGui::Checkbox("Show Roles", &cfg.show_roles);
                ImGui::Checkbox("Show Distance", &cfg.show_distance);
                ImGui::Checkbox("Show Dead Players", &cfg.show_dead_players);
                ImGui::Checkbox("Ghost Indicator", &cfg.show_ghost_indicator);
                ImGui::Checkbox("Kill Cooldown", &cfg.show_kill_cooldown);

                ImGui::Separator();
                ImGui::SliderFloat("Box Thickness", &cfg.box_thickness, 0.5f, 5.0f);
                ImGui::SliderFloat("Font Size", &cfg.font_size, 8.f, 24.f);
                ImGui::SliderFloat("Max Distance", &cfg.max_draw_distance, 10.f, 200.f);

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Radar")) {
                ImGui::Checkbox("Show Radar", &cfg.show_radar);
                ImGui::SliderFloat("Radar Size", &cfg.radar_size, 100.f, 400.f);
                ImGui::SliderFloat("Radar Range", &cfg.radar_range, 10.f, 100.f);
                ImGui::SliderFloat("Radar X", &cfg.radar_x, 0.f, 500.f);
                ImGui::SliderFloat("Radar Y", &cfg.radar_y, 0.f, 500.f);
                ImGui::SliderFloat("Radar Opacity", &cfg.radar_opacity, 0.1f, 1.f);

                ImGui::Separator();
                ImGui::Text("Minimap (PUA-style)");
                ImGui::Checkbox("Show Minimap", &cfg.show_minimap);
                ImGui::Checkbox("Auto-detect Map (LSH)",
                                &cfg.minimap_auto_detect);
                static const char* map_names[] = {
                    "0 Ancient Sands", "1 The Basement", "2 Jungle Temple",
                    "3 GooseChapel",   "4 Mallard Manor","5 NEXUS Colony",
                    "6 BlackSwan",     "7 SS MotherGoose",
                };
                ImGui::BeginDisabled(cfg.minimap_auto_detect);
                ImGui::Combo("Current Map", &cfg.minimap_selected,
                             map_names, IM_ARRAYSIZE(map_names));
                ImGui::EndDisabled();
                if (cfg.minimap_auto_detect) {
                    ImGui::TextDisabled("Detected map = %d",
                                        snap.current_map);
                }
                ImGui::SliderFloat("Minimap Size", &cfg.minimap_size_px,
                                   160.f, 600.f);
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Colors")) {
                color_edit("Impostor",  cfg.color_impostor);
                color_edit("Crewmate",  cfg.color_crewmate);
                color_edit("Dead",      cfg.color_dead);
                color_edit("Local",     cfg.color_local);
                color_edit("Neutral",   cfg.color_neutral);
                color_edit("Unknown",   cfg.color_unknown);
                color_edit("Cooldown",  cfg.color_cooldown_text);
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Info")) {
                ImGui::Checkbox("Local Player Panel", &cfg.show_local_info);
                ImGui::Checkbox("Meeting Timer", &cfg.show_meeting_timer);
                ImGui::Checkbox("Sabotage Status", &cfg.show_sabotage_status);
                ImGui::Checkbox("Door Status", &cfg.show_door_status);
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Hacks")) {
                ImGui::TextDisabled("Writes to game memory. Use in private "
                                    "lobbies to avoid bans.");
                ImGui::Separator();
                ImGui::Checkbox("Speed Hack", &cfg.speed_hack_enabled);
                ImGui::SliderFloat("Speed (units/s)", &cfg.speed_hack_value,
                                   1.0f, 15.0f, "%.1f");
                ImGui::TextDisabled("Base speed is ~5.0");

                ImGui::Separator();
                ImGui::TextDisabled("[Cooldown hack disabled ??triggered account warning]");

                ImGui::Separator();
                ImGui::Checkbox("Zoom Hack", &cfg.zoom_hack.enabled);
                if (cfg.zoom_hack.enabled) {
                    ImGui::SliderFloat("Ortho Size", &cfg.zoom_hack.target_ortho,
                                       4.0f, 60.0f, "%.1f");
                    ImGui::TextDisabled("Game default ~16. Lower = zoom in.");
                }

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Performance")) {
                ImGui::SliderInt("Read Interval (ms)", &cfg.read_interval_ms, 10, 200);
                ImGui::SliderInt("FPS Cap", &cfg.overlay_fps_cap, 15, 144);
                ImGui::SliderInt("Max Players", &cfg.max_cached_players, 4, 64);
                ImGui::Checkbox("Cache Positions", &cfg.cache_positions);

                ImGui::Separator();
                ImGui::Text("Game State");

                ImGui::Text("Players: %d", static_cast<int>(snap.players.size()));
                ImGui::Text("Game State ID: %d", snap.game_state);
                ImGui::Text("In Game: %s", snap.in_game ? "Yes" : "No");
                ImGui::Text("In Meeting: %s", snap.in_meeting ? "Yes" : "No");
                ImGui::Text("GA Base: 0x%016llX",
                    static_cast<unsigned long long>(snap.ga_base));

                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::End();
    }

private:
    void color_edit(const char* label, Color4& col) {
        float c[4] = { col.r, col.g, col.b, col.a };
        if (ImGui::ColorEdit4(label, c, ImGuiColorEditFlags_AlphaBar)) {
            col.r = c[0]; col.g = c[1]; col.b = c[2]; col.a = c[3];
        }
    }
};

}
