# Gossy

Gossy is a Windows x64 C++ project for an ImGui/DirectX 11 overlay targeting Goose Goose Duck. The project is organized as a Visual Studio solution and includes source code for process discovery, module resolution, game-state reading, overlay rendering, menu controls, minimap rendering, and configurable visual options.

This repository is provided for educational and research purposes. Use it only in environments where you have permission and where it does not violate software terms, fair-play rules, or local law.

## Features

- Windows overlay built with DirectX 11 and ImGui
- Goose Goose Duck process and `GameAssembly.dll` discovery
- Memory-reader driven game-state snapshots
- ESP rendering, radar/minimap support, and configurable menu
- Optional gameplay-related configuration hooks
- Bundled ImGui vendor sources
- Visual Studio solution for Debug and Release x64 builds

## Project Structure

```text
.
|-- Goosssy.sln
|-- GoosssyESP.vcxproj
|-- img/
|   `-- maps/
|-- src/
|   `-- esp/
|       |-- core/
|       |-- data/
|       |-- hacks/
|       |-- render/
|       `-- vendor/
`-- vendor/
    `-- imgui/
```

## Requirements

- Windows 10 or newer
- Visual Studio 2022
- MSVC v143 toolset
- Windows SDK 10.0
- x64 build target
- A compatible driver/session layer expected by `DriverComm`

## Build

1. Open `Goosssy.sln` in Visual Studio 2022.
2. Select `x64` as the target platform.
3. Choose either `Debug` or `Release`.
4. Build the `GoosssyESP` project.

Build outputs are written under:

```text
x64/<Configuration>/
```

## Runtime Notes

The executable expects a driver session to be available before startup. It waits for a running Goose Goose Duck process, resolves `GameAssembly.dll`, starts the game-state reader, and then creates the overlay.

Default controls shown by the app:

```text
INSERT  - Toggle ESP on/off
HOME    - Toggle config menu
END     - Toggle radar
ESC     - Exit
```

## Repository Notes

- Visual Studio user files, build outputs, logs, and intermediate artifacts are ignored by `.gitignore`.
- Map images are stored in `img/maps/`.
- ImGui is vendored under `vendor/imgui/`.

## Disclaimer

This code is not affiliated with Goose Goose Duck, Gaggle Studios, Microsoft, or ImGui. The author is responsible for how the software is built, distributed, and used.
