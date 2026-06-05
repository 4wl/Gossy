#pragma once

#include <d3d11.h>
#include <imgui.h>
#include <cstdio>
#include "game_data.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace esp {

struct MapData {
    ID3D11ShaderResourceView* texture = nullptr;
    int   width  = 0;
    int   height = 0;

    float scale_to_game = 1.0f;
    float offset_x = 0.0f;
    float offset_y = 0.0f;
    const char* name = "?";
};

class Minimap {
public:
    static constexpr int NUM_MAPS = 8;

    bool init(ID3D11Device* dev) {
        struct Init { const char* path; const char* name; float scale; float ox; float oy; };

        static const Init init_data[NUM_MAPS] = {
            { "0.png", "Ancient Sands",   0.086f,  -53.24f, -29.55f },
            { "1.png", "The Basement",    0.0f,    -45.60f, -24.82f },
            { "2.png", "Jungle Temple",   0.0847f, -41.08f, -40.58f },
            { "3.png", "GooseChapel",     0.08f,   -36.21f, -40.23f },
            { "4.png", "Mallard Manor",   0.0585f, -28.12f, -42.44f },
            { "5.png", "NEXUS Colony",    0.0948f, -68.08f, -44.96f },
            { "6.png", "BlackSwan",       0.0585f, -28.12f, -42.44f },
            { "7.png", "SS MotherGoose",  0.0947f, -66.84f, -28.49f },
        };

        char exe_dir[MAX_PATH]{};
        GetModuleFileNameA(nullptr, exe_dir, MAX_PATH);
        for (int up = 0; up < 3; up++) {
            char* s = strrchr(exe_dir, '\\');
            if (s) *s = '\0';
        }
        for (int i = 0; i < NUM_MAPS; i++) {
            char full[MAX_PATH]{};
            snprintf(full, MAX_PATH, "%s\\img\\maps\\%s", exe_dir, init_data[i].path);
            if (!load_texture(dev, full, m_maps[i])) {
                printf("[!] Minimap: failed to load %s\n", full);
            } else {
                printf("[+] Minimap loaded %s (%dx%d)\n", full,
                       m_maps[i].width, m_maps[i].height);
            }
            m_maps[i].name = init_data[i].name;
            m_maps[i].offset_x = init_data[i].ox;
            m_maps[i].offset_y = init_data[i].oy;

            if (i == 1 && m_maps[i].width > 0)
                m_maps[i].scale_to_game = 78.48f / static_cast<float>(m_maps[i].width);
            else
                m_maps[i].scale_to_game = init_data[i].scale;
        }
        return true;
    }

    void draw(const GameSnapshot& snap, int selected_map, float panel_size_px,
              float overlay_w, float overlay_h) {
        if (selected_map < 0 || selected_map >= NUM_MAPS) return;
        const MapData& m = m_maps[selected_map];
        if (!m.texture || m.width <= 0 || m.height <= 0) return;

        float display_scale = panel_size_px / static_cast<float>(
            m.width > m.height ? m.width : m.height);
        float disp_w = m.width  * display_scale;
        float disp_h = m.height * display_scale;

        float panel_right  = overlay_w - 16.f;
        float panel_top    = 16.f;
        float panel_left   = panel_right - disp_w;
        float panel_bottom = panel_top + disp_h;

        ImDrawList* dl = ImGui::GetBackgroundDrawList();

        dl->AddRectFilled({panel_left - 4, panel_top - 4},
                          {panel_right + 4, panel_bottom + 4},
                          IM_COL32(0, 0, 0, 160), 4.f);
        dl->AddImage((ImTextureID)m.texture,
                     {panel_left, panel_top}, {panel_right, panel_bottom});
        dl->AddRect({panel_left, panel_top}, {panel_right, panel_bottom},
                    IM_COL32(255, 255, 255, 200), 0.f, 0, 1.5f);

        dl->AddText({panel_left + 4, panel_top + 2},
                    IM_COL32(255, 255, 255, 220), m.name);

        for (const auto& p : snap.players) {
            float img_x, img_y;
            world_to_image_px(m, p.pos_x, p.pos_y, img_x, img_y);

            float sx = panel_left  + img_x * display_scale;
            float sy = panel_bottom - img_y * display_scale;

            if (sx < panel_left || sx > panel_right ||
                sy < panel_top  || sy > panel_bottom) continue;

            ImU32 col;
            float radius = 4.f;
            if (p.is_local) {
                col = IM_COL32(0, 255, 255, 255);
                radius = 5.f;
            } else if (p.is_dead || p.is_ghost) {
                col = IM_COL32(120, 120, 120, 180);
            } else {
                col = IM_COL32(255, 80, 80, 230);
            }
            dl->AddCircleFilled({sx, sy}, radius, col);
            dl->AddCircle({sx, sy}, radius, IM_COL32(0, 0, 0, 200), 0, 1.2f);
            if (!p.name.empty()) {
                dl->AddText({sx + 6, sy - 6},
                            IM_COL32(255, 255, 255, 220), p.name.c_str());
            }
        }
    }

    const char* map_name(int i) const {
        return (i >= 0 && i < NUM_MAPS) ? m_maps[i].name : "?";
    }

private:
    MapData m_maps[NUM_MAPS];

    static void world_to_image_px(const MapData& m,
                                  float wx, float wy,
                                  float& img_x, float& img_y) {
        if (m.scale_to_game <= 0.f) { img_x = img_y = 0.f; return; }
        img_x = (wx - m.offset_x) / m.scale_to_game;
        img_y = (wy - m.offset_y) / m.scale_to_game;
    }

    static bool load_texture(ID3D11Device* dev, const char* filename,
                             MapData& out) {
        int w = 0, h = 0;
        unsigned char* data = stbi_load(filename, &w, &h, nullptr, 4);
        if (!data) return false;

        D3D11_TEXTURE2D_DESC desc{};
        desc.Width = w;
        desc.Height = h;
        desc.MipLevels = 1;
        desc.ArraySize = 1;
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.SampleDesc.Count = 1;
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

        D3D11_SUBRESOURCE_DATA sub{};
        sub.pSysMem = data;
        sub.SysMemPitch = w * 4;

        ID3D11Texture2D* tex = nullptr;
        HRESULT hr = dev->CreateTexture2D(&desc, &sub, &tex);
        if (FAILED(hr) || !tex) { stbi_image_free(data); return false; }

        D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc{};
        srv_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        srv_desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        srv_desc.Texture2D.MipLevels = 1;
        dev->CreateShaderResourceView(tex, &srv_desc, &out.texture);
        tex->Release();
        stbi_image_free(data);

        out.width = w;
        out.height = h;
        return true;
    }
};

}
