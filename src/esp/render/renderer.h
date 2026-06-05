#pragma once

#include "overlay.h"
#include "game_data.h"
#include "config.h"

#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

#include <cmath>
#include <cstdio>
#include <string>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
    HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace esp {

class Renderer {
public:
    Renderer() = default;
    ~Renderer() { shutdown(); }

    bool init(Overlay& overlay) {
        m_overlay = &overlay;

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
        io.IniFilename = nullptr;

        apply_style();

        ImGui_ImplWin32_Init(overlay.hwnd());
        ImGui_ImplDX11_Init(overlay.device(), overlay.context());

        m_initialized = true;
        return true;
    }

    void shutdown() {
        if (!m_initialized) return;
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();
        m_initialized = false;
    }

    void begin_frame() {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
    }

    void end_frame() {
        ImGui::Render();
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }

    void draw_line(float x1, float y1, float x2, float y2,
                   const Color4& col, float thickness = 1.f) {
        auto* dl = ImGui::GetBackgroundDrawList();
        dl->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), to_im_col(col), thickness);
    }

    void draw_rect(float x, float y, float w, float h,
                   const Color4& col, float thickness = 1.f) {
        auto* dl = ImGui::GetBackgroundDrawList();
        dl->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), to_im_col(col), 0.f, 0, thickness);
    }

    void draw_rect_filled(float x, float y, float w, float h,
                          const Color4& col) {
        auto* dl = ImGui::GetBackgroundDrawList();
        dl->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), to_im_col(col));
    }

    void draw_corner_box(float x, float y, float w, float h,
                         const Color4& col, float thickness = 1.5f) {
        auto* dl = ImGui::GetBackgroundDrawList();
        float corner_len = fminf(w, h) * 0.25f;
        ImU32 c = to_im_col(col);

        dl->AddLine(ImVec2(x, y), ImVec2(x + corner_len, y), c, thickness);
        dl->AddLine(ImVec2(x, y), ImVec2(x, y + corner_len), c, thickness);

        dl->AddLine(ImVec2(x + w, y), ImVec2(x + w - corner_len, y), c, thickness);
        dl->AddLine(ImVec2(x + w, y), ImVec2(x + w, y + corner_len), c, thickness);

        dl->AddLine(ImVec2(x, y + h), ImVec2(x + corner_len, y + h), c, thickness);
        dl->AddLine(ImVec2(x, y + h), ImVec2(x, y + h - corner_len), c, thickness);

        dl->AddLine(ImVec2(x + w, y + h), ImVec2(x + w - corner_len, y + h), c, thickness);
        dl->AddLine(ImVec2(x + w, y + h), ImVec2(x + w, y + h - corner_len), c, thickness);
    }

    void draw_text(float x, float y, const std::string& text,
                   const Color4& col, bool centered = false, float size = 0.f) {
        auto* dl = ImGui::GetBackgroundDrawList();
        ImFont* font = ImGui::GetFont();
        float font_size = (size > 0.f) ? size : ImGui::GetFontSize();

        ImVec2 text_size = font->CalcTextSizeA(font_size, FLT_MAX, 0.f, text.c_str());

        float draw_x = centered ? (x - text_size.x * 0.5f) : x;
        float draw_y = y;

        dl->AddText(font, font_size, ImVec2(draw_x + 1.f, draw_y + 1.f),
            IM_COL32(0, 0, 0, 200), text.c_str());

        dl->AddText(font, font_size, ImVec2(draw_x, draw_y),
            to_im_col(col), text.c_str());
    }

    void draw_circle(float cx, float cy, float radius,
                     const Color4& col, float thickness = 1.f, int segments = 32) {
        auto* dl = ImGui::GetBackgroundDrawList();
        dl->AddCircle(ImVec2(cx, cy), radius, to_im_col(col), segments, thickness);
    }

    void draw_circle_filled(float cx, float cy, float radius,
                            const Color4& col, int segments = 32) {
        auto* dl = ImGui::GetBackgroundDrawList();
        dl->AddCircleFilled(ImVec2(cx, cy), radius, to_im_col(col), segments);
    }

    bool world_to_screen(float wx, float wy, const CameraData& cam,
                         float& sx, float& sy) {
        float scr_w = static_cast<float>(m_overlay->width());
        float scr_h = static_cast<float>(m_overlay->height());

        if (cam.ortho_size <= 0.f) return false;

        float scale = scr_h / (2.f * cam.ortho_size);

        sx = (wx - cam.pos_x) * scale + scr_w * 0.5f;
        sy = -(wy - cam.pos_y) * scale + scr_h * 0.5f;

        float margin = 50.f;
        return (sx > -margin && sx < scr_w + margin &&
                sy > -margin && sy < scr_h + margin);
    }

    Overlay* overlay() const { return m_overlay; }
    bool initialized() const { return m_initialized; }

private:
    Overlay* m_overlay = nullptr;
    bool     m_initialized = false;

    static ImU32 to_im_col(const Color4& c) {
        return IM_COL32(
            static_cast<int>(c.r * 255.f),
            static_cast<int>(c.g * 255.f),
            static_cast<int>(c.b * 255.f),
            static_cast<int>(c.a * 255.f));
    }

    void apply_style() {
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding    = 8.f;
        style.FrameRounding     = 4.f;
        style.GrabRounding      = 4.f;
        style.PopupRounding     = 4.f;
        style.ScrollbarRounding = 6.f;
        style.TabRounding       = 4.f;
        style.WindowBorderSize  = 1.f;
        style.FrameBorderSize   = 0.f;
        style.WindowPadding     = ImVec2(12.f, 12.f);
        style.FramePadding      = ImVec2(8.f, 4.f);
        style.ItemSpacing       = ImVec2(8.f, 6.f);
        style.IndentSpacing     = 20.f;
        style.ScrollbarSize     = 12.f;
        style.GrabMinSize       = 8.f;
        style.WindowTitleAlign  = ImVec2(0.5f, 0.5f);

        ImVec4* c = style.Colors;
        c[ImGuiCol_WindowBg]           = ImVec4(0.06f, 0.06f, 0.10f, 0.92f);
        c[ImGuiCol_Border]             = ImVec4(0.30f, 0.25f, 0.50f, 0.50f);
        c[ImGuiCol_FrameBg]            = ImVec4(0.12f, 0.12f, 0.20f, 0.90f);
        c[ImGuiCol_FrameBgHovered]     = ImVec4(0.20f, 0.18f, 0.35f, 0.90f);
        c[ImGuiCol_FrameBgActive]      = ImVec4(0.25f, 0.22f, 0.45f, 0.90f);
        c[ImGuiCol_TitleBg]            = ImVec4(0.08f, 0.07f, 0.15f, 1.00f);
        c[ImGuiCol_TitleBgActive]      = ImVec4(0.12f, 0.10f, 0.25f, 1.00f);
        c[ImGuiCol_CheckMark]          = ImVec4(0.55f, 0.40f, 1.00f, 1.00f);
        c[ImGuiCol_SliderGrab]         = ImVec4(0.50f, 0.35f, 0.90f, 1.00f);
        c[ImGuiCol_SliderGrabActive]   = ImVec4(0.60f, 0.45f, 1.00f, 1.00f);
        c[ImGuiCol_Button]             = ImVec4(0.18f, 0.15f, 0.35f, 1.00f);
        c[ImGuiCol_ButtonHovered]      = ImVec4(0.25f, 0.22f, 0.50f, 1.00f);
        c[ImGuiCol_ButtonActive]       = ImVec4(0.35f, 0.30f, 0.60f, 1.00f);
        c[ImGuiCol_Header]             = ImVec4(0.18f, 0.15f, 0.35f, 1.00f);
        c[ImGuiCol_HeaderHovered]      = ImVec4(0.25f, 0.22f, 0.50f, 1.00f);
        c[ImGuiCol_HeaderActive]       = ImVec4(0.35f, 0.30f, 0.60f, 1.00f);
        c[ImGuiCol_Tab]                = ImVec4(0.12f, 0.10f, 0.22f, 1.00f);
        c[ImGuiCol_TabHovered]         = ImVec4(0.30f, 0.25f, 0.55f, 1.00f);
        c[ImGuiCol_TabActive]          = ImVec4(0.22f, 0.18f, 0.40f, 1.00f);
        c[ImGuiCol_Text]               = ImVec4(0.90f, 0.90f, 0.95f, 1.00f);
        c[ImGuiCol_TextDisabled]       = ImVec4(0.50f, 0.50f, 0.55f, 1.00f);
        c[ImGuiCol_PopupBg]            = ImVec4(0.08f, 0.07f, 0.14f, 0.96f);
    }
};

}
