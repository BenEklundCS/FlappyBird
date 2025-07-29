# C++ Raylib Game Template

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://cplusplus.com/) 
[![Raylib](https://img.shields.io/badge/Raylib-FA8B00?style=for-the-badge&logo=raylib&logoColor=white)](https://www.raylib.com/) 
[![ImGui](https://img.shields.io/badge/ImGui-009DFF?style=for-the-badge&logo=imgui&logoColor=white)](https://github.com/ocornut/imgui) 

A simple, reusable C++ game template using [Raylib](https://www.raylib.com/), ImGui, and rlImGui. Built for the **20 Games Challenge** and anyone looking to prototype 2D games with low-level control.

This template is cross-platform (Windows/Linux) and includes a working CMake setup that automatically downloads dependencies if not found.

---

## 🎮 Features

- ✅ **C++17 + Raylib** setup with proper project structure
- ✅ **ImGui & rlImGui** support out of the box (UI overlays, debug tools)
- ✅ **CMake-based build** (works with CLion, VSCode, or terminal)
- ✅ **Cross-platform support** (tested on Windows 11 & Linux Mint)
- ✅ Lightweight and minimal boilerplate—ideal for small games or prototypes

---

## 📁 Project Structure
```
project-root/
├── include/        # Header files
├── src/            # Source files
├── CMakeLists.txt  # Build configuration
└── README.md
```


---

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/BenEklundCS/YourTemplateRepo.git
cd YourTemplateRepo
```

### 2. Build the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
./MyGameProject   # or .\MyGameProject.exe on Windows
```


