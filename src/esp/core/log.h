#pragma once

#include <cstdio>
#include <cstdarg>
#include <mutex>
#include <windows.h>

inline FILE*& goosssy_logfile() { static FILE* f = nullptr; return f; }
inline std::mutex& goosssy_logmu() { static std::mutex m; return m; }

inline void goosssy_log_init() {
    char exe[MAX_PATH]{};
    GetModuleFileNameA(nullptr, exe, MAX_PATH);
    char* slash = strrchr(exe, '\\');
    if (slash) *(slash + 1) = '\0';
    char path[MAX_PATH]{};
    snprintf(path, MAX_PATH, "%sGoosssy.log", exe);
    FILE* f = nullptr;
    fopen_s(&f, path, "w");
    goosssy_logfile() = f;
    if (f) {
        fprintf(f, "=== Goosssy log opened: %s ===\n", path);
        fflush(f);
        printf("[*] Logging to %s\n", path);
    } else {
        printf("[!] Failed to open log file at %s\n", path);
    }
}

inline int goosssy_log(const char* fmt, ...) {
    std::lock_guard<std::mutex> g(goosssy_logmu());
    va_list a, b;
    va_start(a, fmt); va_copy(b, a);
    int r = vprintf(fmt, a);
    FILE* f = goosssy_logfile();
    if (f) { vfprintf(f, fmt, b); fflush(f); }
    va_end(b); va_end(a);
    return r;
}

#define printf goosssy_log
