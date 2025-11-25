# Mistral Core

![C++ Standard](https://img.shields.io/badge/C%2B%2B-20-blue.svg?style=flat&logo=c%2B%2B)
![License](https://img.shields.io/badge/License-Zlib-green.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)

**Mistral** is a modern, modular, and lightweight Game Engine core written in **C++20**. Built on top of the robust [**Raylib**](https://github.com/raysan5/raylib) framework, it provides a flexible Component-based architecture and a hierarchical Scene Graph, designed to serve as the technological foundation for interactive tools and games.

> **Note:** This repository contains the **Core Framework** library.
> If you are looking for the visual editor, please visit the [Mistral Editor](https://github.com/WindmillStudios/Mistral-Editor) repository.

## ✨ Key Features

* **Modern C++20:** Built with the latest standards for cleaner, safer code.
* **Component System:** Flexible `Component` architecture with parent/child hierarchy and lifecycle events (`Update`, `Render`, `Destroy`).
* **Scene Graph:** Robust `Spatial` system handling local/world transformations, rotation, and scaling.
* **Render Abstraction:** Decoupled rendering logic via `IRenderPipeline`, allowing custom rendering strategies.
* **Resource Management:** Centralized and efficient loading for Textures, Models, Audio, and Fonts.
* **Math Library:** Integrated wrappers for Vectors, Matrices, and Quaternions ensuring seamless compatibility.
* **ImGui Integration:** Native support for **ImGui**, making it easy to build debug tools and custom UIs.

## 📦 Installation

Mistral is designed to be consumed as a **Static Library**. The recommended way to integrate it into your project (Game or Tool) is using CMake's `FetchContent`.

Add the following to your project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    Mistral
    GIT_REPOSITORY https://github.com/WindmillStudio/Mistral-Core.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(Mistral)

target_link_libraries(${PROJECT_NAME} PRIVATE Mistral)