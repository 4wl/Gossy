

#include <windows.h>
#include <tlhelp32.h>
#include <cstdio>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>

#include "log.h"

#include "driver_comm.h"
#include "module_resolver.h"
#include "offsets.h"
#include "config.h"
#include "game_data.h"
#include "memory_reader.h"
#include "overlay.h"
#include "renderer.h"
#include "esp_draw.h"
#include "menu.h"
#include "minimap.h"
#include "hacks.h"
#include "cooldown_hack.h"
#include "zoom_hack.h"

#include <imgui.cpp>
#include <imgui_draw.cpp>
#include <imgui_tables.cpp>
#include <imgui_widgets.cpp>
#include <imgui_demo.cpp>
#include <imgui_impl_dx11.cpp>
#include <imgui_impl_win32.cpp>

static uint32_t find_process_id(const wchar_t* name) {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return 0;
    PROCESSENTRY32W pe{}; pe.dwSize = sizeof(pe);
    uint32_t pid = 0;
    if (Process32FirstW(snap, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, name) == 0) { pid = pe.th32ProcessID; break; }
        } while (Process32NextW(snap, &pe));
    }
    CloseHandle(snap);
    return pid;
}

static uint32_t find_ggd() {
    static const wchar_t* names[] = {
        L"Goose Goose Duck.exe",
        L"GooseGooseDuck.exe",
        L"GGD.exe",
    };
    for (auto* n : names) {
        uint32_t pid = find_process_id(n);
        if (pid) return pid;
    }
    return 0;
}

namespace con {
    static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    inline void color(WORD a)  { SetConsoleTextAttribute(h, a); }
    inline void reset()  { color(7); }
    inline void green()  { color(FOREGROUND_GREEN | FOREGROUND_INTENSITY); }
    inline void red()    { color(FOREGROUND_RED   | FOREGROUND_INTENSITY); }
    inline void yellow() { color(FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_INTENSITY); }
    inline void cyan()   { color(FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_INTENSITY); }
    inline void white()  { color(FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
}

int main() {

    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode = 0;
        if (GetConsoleMode(h, &mode))
            SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }

    goosssy_log_init();

    con::cyan();
    printf(R"GOOSSSY(
                                                                     
                         @@@@%%%%%%%%@@@@       %%%%%%               
                      @@%%%%%%%%%%%%%%%%%%@%%###*=-*##%%             
                    @@%%%%%%%########%%%%%%%%@##########%            
       @@@         @%%%%%################%%%%%%@#########%           
    @@%%%@       @@%%%%####################%%%%%@%###%###%           
 @@@%%%%%@      @@%%%%%#####################%%%%%%@#%%###%           
 @@%%%%%%@@    @@%%%%%%%#####################%%%%%%@%%%##%           
 @@%%%%%%%@@@@@@%%%%%%%%%%%%%%%%%###########%%%%%%%%@  %%%           
  @%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#####%%%%%%%%%%@@               
  @@%%%%%%%%%%%%%#+*#%%%#***###%%%%%%%%%%%%%%%%%%%%%%@               
  @@%%%%%%%%%%%#-.:.-#%++@@+.....-#%%%%%%%%%%%%%%%%%%@@              
   @@%%%%%%%%%%+..-::#*.-+......*@*::%%%%%%%%%%%%%%%%%@              
    @@%%%%%%%%%+::::=*..*#:.....-:#=..*%%%%%%%%%%%%%%%%@             
     @@%%%%%%%%%--:..:=:..:::..%%=....%%%%%%%%%%%%%%%%%%@@     @@@@  
      @@%%%%%%%%*:...-@@=......-:...:%%*-:.-#%%%%%%%%%%%%%%@@@%%%%%@ 
       @@%%%%%%%+....*%-..+:::-+%=:..==.::..-%%%%%%%%%%%%%%%%%%%%%%@@
     ...*@%%%%#%+....*%=.=+...@@*:.....:::.:=%%%%%%%%%%%%%%%%%%%%%%%@
   :.....:#@+...+:...-=-=**-=*%%:........:-+%%%%%%%%%%%%%%%%%%%%%%@@@
   ::....  ....:%#:..:---:----=.....:=###%%%%%%%%%%%%%%%%%%%%%%@@@@  
    :..   ..  .*%%#-:.:------:....:-#%%%%%%%%%%%%%%%%%%%%%%%@@@@     
      -:..    .=###---::::.....::-*%%%%%%%%%%%%%%%%%%%%%%@@@@        
        --::..=+++=:::--------=+++*#%%%%%%+...+%%%%@@@@@@            
           ##****=::::-:-::::-=++++***+..  ...#@@@@@                 
             ### --::-=*=::::-+##****#. ..  .:                       
                 #+=+++++=---=++######=. .   ..::                    
                 #+++=:+++++++++*   ##+::. .. ...-                   
                ##+++++++++++++++#       -:. :..:-                   
                ##++*************##        -----                     
                  *****************                                  
                  #*******#*********                                 
          ++++++   *******  #********+    +++++++                    
       +=-++++++++++++.+*      **+:-++++++++++++-=++                 
     ++==++++++++++++++**        **++++++++++++++==++                
    **++++++++++++++*****        *******+++++++++++++**              
       ***********  ***#                 ***********                               
)GOOSSSY");

    con::reset();
    printf("\n");

    con::white();
    printf("[*] Initializing driver session...\n");
    DriverComm driver;
    if (!driver.init()) {
        con::red();
        printf("[!] Driver bootstrap failed. Is your driver loaded?\n");
        con::reset();
        printf("    Press any key to exit.\n");
        _getch();
        return 1;
    }
    con::green();
    printf("[+] Driver session established.\n");

    con::white();
    printf("[*] Locating Goose Goose Duck...\n");
    uint32_t pid = 0;
    while (!pid) {
        pid = find_ggd();
        if (!pid) {
            con::yellow();
            printf("[!] GGD not running. Waiting...\r");
            con::reset();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    con::green();
    printf("[+] PID: %u                          \n", pid);

    con::white();
    printf("[*] Locating GameAssembly.dll...\n");
    ModuleResolver mods(driver, pid);
    if (!mods.init()) {
        con::red();
        printf("[!] Failed to query PEB/CR3.\n");
        _getch();
        return 1;
    }

    std::optional<ModuleInfo> ga;
    auto ga_start = std::chrono::steady_clock::now();
    int ga_attempts = 0;
    while (!ga) {

        mods.refresh();

        auto all_mods = mods.enumerate_modules();
        ga_attempts++;

        for (const auto& m : all_mods) {
            if (_wcsicmp(m.name.c_str(), L"GameAssembly.dll") == 0) {
                ga = m;
                break;
            }
        }

        if (!ga) {
            con::yellow();
            printf("[!] GameAssembly.dll not loaded yet. %d modules found (attempt %d)...\r",
                   static_cast<int>(all_mods.size()), ga_attempts);
            con::reset();

            auto elapsed = std::chrono::steady_clock::now() - ga_start;
            if (elapsed > std::chrono::seconds(120)) {
                con::red();
                printf("\n[!] Timed out waiting for GameAssembly.dll after 120s.\n");
                printf("    Make sure the game has fully loaded past the splash screen.\n");
                printf("    Modules found: %d\n", static_cast<int>(all_mods.size()));
                if (!all_mods.empty()) {
                    printf("    Last seen modules:\n");
                    int show = (all_mods.size() < 10) ? static_cast<int>(all_mods.size()) : 10;
                    for (int i = 0; i < show; i++) {
                        printf("      %ls @ 0x%llX\n", all_mods[i].name.c_str(),
                               static_cast<unsigned long long>(all_mods[i].base));
                    }
                }
                _getch();
                return 1;
            }

            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    con::green();
    printf("[+] GameAssembly.dll @ 0x%016llX (%u MB)              \n",
           static_cast<unsigned long long>(ga->base), ga->size / (1024 * 1024));

    con::white();
    printf("[*] Starting memory reader...\n");
    esp::GameState game_state;
    esp::MemoryReader reader(driver, pid, ga->base, game_state);
    reader.start();
    con::green();
    printf("[+] Memory reader running.\n");

    con::white();
    printf("[*] Waiting for first data snapshot...\n");
    auto wait_start = std::chrono::steady_clock::now();
    while (!game_state.has_data()) {
        auto elapsed = std::chrono::steady_clock::now() - wait_start;
        if (elapsed > std::chrono::seconds(30)) {
            con::red();
            printf("[!] Timed out waiting for game data. Join a lobby first.\n");
            reader.stop();
            _getch();
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    con::green();
    printf("[+] Data flowing.\n");

    con::white();
    printf("[*] Creating overlay...\n");
    esp::Overlay overlay;
    if (!overlay.init("Goose Goose Duck")) {
        con::yellow();
        printf("[!] Couldn't find 'Goose Goose Duck' window, trying Unity class...\n");
        if (!overlay.init("GooseGooseDuck")) {
            con::red();
            printf("[!] Failed to create overlay. Is the game window visible?\n");
            reader.stop();
            _getch();
            return 1;
        }
    }
    con::green();
    printf("[+] Overlay created (%dx%d).\n", overlay.width(), overlay.height());

    esp::Renderer renderer;
    if (!renderer.init(overlay)) {
        con::red();
        printf("[!] Failed to initialize ImGui renderer.\n");
        reader.stop();
        _getch();
        return 1;
    }

    esp::EspDraw esp_draw(renderer);
    esp::Menu menu;
    esp::Minimap minimap;
    minimap.init(overlay.device());

    con::green();
    printf("[+] ESP fully initialized.\n");
    con::cyan();
    printf("\n  Controls:\n");
    printf("    INSERT  - Toggle ESP on/off\n");
    printf("    HOME    - Toggle config menu\n");
    printf("    END     - Toggle radar\n");
    printf("    ESC     - Exit\n\n");
    con::reset();

    bool running = true;
    auto& cfg = esp::Config::get();

    while (running) {

        if (GetAsyncKeyState(cfg.toggle_esp_key) & 1) {
            cfg.esp_enabled = !cfg.esp_enabled;
        }
        if (GetAsyncKeyState(cfg.toggle_menu_key) & 1) {
            cfg.menu_visible = !cfg.menu_visible;

            LONG_PTR ex_style = GetWindowLongPtrA(overlay.hwnd(), GWL_EXSTYLE);
            if (cfg.menu_visible) {
                ex_style &= ~WS_EX_TRANSPARENT;
                SetForegroundWindow(overlay.hwnd());
            } else {
                ex_style |= WS_EX_TRANSPARENT;
            }
            SetWindowLongPtrA(overlay.hwnd(), GWL_EXSTYLE, ex_style);
        }
        if (GetAsyncKeyState(cfg.toggle_radar_key) & 1) {
            cfg.show_radar = !cfg.show_radar;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 1) {
            running = false;
            break;
        }

        if (!IsWindow(overlay.game_hwnd())) {
            con::yellow();
            printf("[!] Game window lost. Exiting.\n");
            break;
        }

        auto snap = game_state.get();

        static auto last_hack_apply = std::chrono::steady_clock::now();
        if (cfg.speed_hack_enabled && snap.in_game) {
            auto now = std::chrono::steady_clock::now();
            if (now - last_hack_apply > std::chrono::milliseconds(250)) {
                esp::hacks::set_movement_speed(driver, pid, reader.lp_klass(),
                                               cfg.speed_hack_value);
                last_hack_apply = now;
            }
        }

        static esp::zoom::ZoomState zoom_state;
        if (cfg.zoom_hack.enabled && snap.in_game) {
            uint64_t lp_inst = reader.lp_instance();
            if (lp_inst) {
                esp::zoom::apply(driver, pid, lp_inst, cfg.zoom_hack, zoom_state);
            }
        }

        bool ok = overlay.frame([&]() {
            renderer.begin_frame();

            esp_draw.draw(snap);

            if (cfg.show_minimap) {
                int map_idx = cfg.minimap_selected;
                if (cfg.minimap_auto_detect && snap.current_map >= 0 &&
                    snap.current_map < esp::Minimap::NUM_MAPS) {
                    map_idx = snap.current_map;
                }
                minimap.draw(snap, map_idx, cfg.minimap_size_px,
                             static_cast<float>(overlay.width()),
                             static_cast<float>(overlay.height()));
            }

            menu.draw(snap);

            renderer.end_frame();
        });

        if (!ok) {
            running = false;
        }

        if (cfg.overlay_fps_cap > 0 && cfg.overlay_fps_cap < 300) {
            int target_ms = 1000 / cfg.overlay_fps_cap;
            std::this_thread::sleep_for(std::chrono::milliseconds(target_ms));
        }
    }

    con::white();
    printf("[*] Shutting down...\n");
    reader.stop();
    renderer.shutdown();
    overlay.shutdown();

    con::green();
    printf("[+] Clean exit.\n");
    con::reset();
    return 0;
}
