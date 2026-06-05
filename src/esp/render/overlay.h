#pragma once

#include <windows.h>
#include <dwmapi.h>
#include <d3d11.h>
#include <dxgi.h>
#include <string>
#include <functional>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dwmapi.lib")

extern LRESULT ImGui_ImplWin32_WndProcHandler(
    HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace esp {

class Overlay {
public:
    using RenderCallback = std::function<void()>;

    Overlay() = default;
    ~Overlay() { shutdown(); }

    bool init(const std::string& target_window_title) {
        m_target_title = target_window_title;

        m_game_hwnd = FindWindowA(nullptr, target_window_title.c_str());
        if (!m_game_hwnd) {
            m_game_hwnd = FindWindowA("UnityWndClass", nullptr);
        }
        if (!m_game_hwnd) return false;

        update_window_rect();

        WNDCLASSEXA wc{};
        wc.cbSize        = sizeof(wc);
        wc.style         = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc   = wnd_proc_static;
        wc.hInstance     = GetModuleHandleA(nullptr);
        wc.lpszClassName = "GGD_Overlay_WC";
        if (!RegisterClassExA(&wc)) return false;

        m_hwnd = CreateWindowExA(
            WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED | WS_EX_TOOLWINDOW,
            wc.lpszClassName,
            "GGD Overlay",
            WS_POPUP,
            m_rect.left, m_rect.top,
            m_width, m_height,
            nullptr, nullptr,
            wc.hInstance,
            this);
        if (!m_hwnd) return false;

        SetLayeredWindowAttributes(m_hwnd, 0, 255, LWA_ALPHA);

        MARGINS margins = { -1, -1, -1, -1 };
        DwmExtendFrameIntoClientArea(m_hwnd, &margins);

        ShowWindow(m_hwnd, SW_SHOWDEFAULT);
        UpdateWindow(m_hwnd);

        if (!init_d3d11()) {
            shutdown();
            return false;
        }

        m_initialized = true;
        return true;
    }

    bool frame(RenderCallback render_fn) {
        MSG msg{};
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) return false;
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        update_window_rect();

        if (!IsWindow(m_game_hwnd)) return false;

        float clear_color[4] = { 0.f, 0.f, 0.f, 0.f };
        m_context->ClearRenderTargetView(m_rtv, clear_color);

        if (render_fn) render_fn();

        m_swap_chain->Present(1, 0);
        return true;
    }

    void shutdown() {
        if (m_rtv)        { m_rtv->Release();        m_rtv = nullptr; }
        if (m_swap_chain)  { m_swap_chain->Release();  m_swap_chain = nullptr; }
        if (m_context)     { m_context->Release();     m_context = nullptr; }
        if (m_device)      { m_device->Release();      m_device = nullptr; }
        if (m_hwnd)        { DestroyWindow(m_hwnd);     m_hwnd = nullptr; }
        m_initialized = false;
    }

    HWND                 hwnd()       const { return m_hwnd; }
    HWND                 game_hwnd()  const { return m_game_hwnd; }
    ID3D11Device*        device()     const { return m_device; }
    ID3D11DeviceContext* context()    const { return m_context; }
    IDXGISwapChain*      swap_chain() const { return m_swap_chain; }
    ID3D11RenderTargetView* rtv()     const { return m_rtv; }
    int                  width()      const { return m_width; }
    int                  height()     const { return m_height; }
    bool                 initialized() const { return m_initialized; }

private:
    HWND        m_hwnd      = nullptr;
    HWND        m_game_hwnd = nullptr;
    RECT        m_rect{};
    int         m_width  = 1920;
    int         m_height = 1080;
    std::string m_target_title;
    bool        m_initialized = false;

    ID3D11Device*           m_device     = nullptr;
    ID3D11DeviceContext*    m_context    = nullptr;
    IDXGISwapChain*         m_swap_chain = nullptr;
    ID3D11RenderTargetView* m_rtv        = nullptr;

    void update_window_rect() {
        if (!m_game_hwnd || !IsWindow(m_game_hwnd)) return;

        RECT r{};
        GetWindowRect(m_game_hwnd, &r);

        int new_w = r.right - r.left;
        int new_h = r.bottom - r.top;

        if (new_w != m_width || new_h != m_height ||
            r.left != m_rect.left || r.top != m_rect.top) {
            m_rect   = r;
            m_width  = new_w;
            m_height = new_h;

            if (m_hwnd) {
                MoveWindow(m_hwnd, m_rect.left, m_rect.top, m_width, m_height, TRUE);

                if (m_swap_chain && m_rtv) {
                    m_rtv->Release();
                    m_rtv = nullptr;
                    m_swap_chain->ResizeBuffers(0, m_width, m_height,
                        DXGI_FORMAT_UNKNOWN, 0);
                    create_rtv();
                }
            }
        }
    }

    bool init_d3d11() {
        DXGI_SWAP_CHAIN_DESC scd{};
        scd.BufferCount       = 1;
        scd.BufferDesc.Width  = m_width;
        scd.BufferDesc.Height = m_height;
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        scd.BufferDesc.RefreshRate.Numerator   = 60;
        scd.BufferDesc.RefreshRate.Denominator = 1;
        scd.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        scd.OutputWindow      = m_hwnd;
        scd.SampleDesc.Count  = 1;
        scd.Windowed          = TRUE;
        scd.SwapEffect        = DXGI_SWAP_EFFECT_DISCARD;
        scd.Flags             = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

        D3D_FEATURE_LEVEL feature_level;
        D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0 };

        HRESULT hr = D3D11CreateDeviceAndSwapChain(
            nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr,
            0, levels, 1,
            D3D11_SDK_VERSION,
            &scd, &m_swap_chain, &m_device, &feature_level, &m_context);

        if (FAILED(hr)) return false;

        return create_rtv();
    }

    bool create_rtv() {
        ID3D11Texture2D* back_buffer = nullptr;
        m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D),
            reinterpret_cast<void**>(&back_buffer));
        if (!back_buffer) return false;

        HRESULT hr = m_device->CreateRenderTargetView(back_buffer, nullptr, &m_rtv);
        back_buffer->Release();

        if (FAILED(hr)) return false;

        m_context->OMSetRenderTargets(1, &m_rtv, nullptr);

        D3D11_VIEWPORT vp{};
        vp.Width    = static_cast<float>(m_width);
        vp.Height   = static_cast<float>(m_height);
        vp.MinDepth = 0.f;
        vp.MaxDepth = 1.f;
        m_context->RSSetViewports(1, &vp);

        return true;
    }

    static LRESULT CALLBACK wnd_proc_static(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
        if (msg == WM_CREATE) {
            auto* cs = reinterpret_cast<CREATESTRUCTA*>(lp);
            SetWindowLongPtrA(hwnd, GWLP_USERDATA,
                reinterpret_cast<LONG_PTR>(cs->lpCreateParams));
        }
        if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wp, lp))
            return 1;
        auto* self = reinterpret_cast<Overlay*>(GetWindowLongPtrA(hwnd, GWLP_USERDATA));
        if (self) return self->wnd_proc(hwnd, msg, wp, lp);
        return DefWindowProcA(hwnd, msg, wp, lp);
    }

    LRESULT wnd_proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
        switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_SIZE:
            if (m_device && wp != SIZE_MINIMIZED) {

            }
            return 0;
        }
        return DefWindowProcA(hwnd, msg, wp, lp);
    }
};

}
