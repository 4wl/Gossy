# Gossy

Gossy is a Windows x64 C++ project for an ImGui/DirectX 11 overlay targeting Goose Goose Duck. The project is organized as a Visual Studio solution and includes source code for process discovery, module resolution, game-state reading, overlay rendering, menu controls, minimap rendering, and configurable visual options.

This project is not finished and should be treated as a work in progress. Some parts may be incomplete, unstable, or require changes before they work in your own environment.

This repository is provided for educational and research purposes. Use it only in environments where you have permission and where it does not violate software terms, fair-play rules, or local law.

## Features

- Windows overlay built with DirectX 11 and ImGui
- Memory-reader driven game-state snapshots
- ESP rendering, radar/minimap support, and configurable menu
- Optional gameplay-related configuration hooks
- Bundled ImGui vendor sources
- Visual Studio solution for Debug and Release x64 builds

## Requirements

- Windows 10 or newer
- Visual Studio 2022
- MSVC v143 toolset
- Windows SDK 10.0
- x64 build target
- A compatible driver/session layer expected by `DriverComm`

## Usage Notice

This project does not include a kernel driver. If you want to use or test it, you must provide your own compatible kernel driver/session implementation for the `DriverComm` layer. Otherwise, you will need to modify the project and experiment with your own memory-access approach.

## Build

1. Open `Goosssy.sln` in Visual Studio 2022.
2. Select `x64` as the target platform.
3. Choose either `Debug` or `Release`.
4. Build the `GoosssyESP` project.

## Runtime Notes

Default controls shown by the app:

```text
INSERT  - Toggle ESP on/off
HOME    - Toggle config menu
END     - Toggle radar
ESC     - Exit
```

## Repository Notes

- Map images are stored in `img/maps/`.
- ImGui is vendored under `vendor/imgui/`.
