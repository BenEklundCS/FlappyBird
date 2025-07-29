# Flappy Bird - Game 1 of the 20 Games Challenge, based on C++ Raylib Game Template

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://cplusplus.com/) 
[![Raylib](https://img.shields.io/badge/Raylib-FA8B00?style=for-the-badge&logo=raylib&logoColor=white)](https://www.raylib.com/) 
[![ImGui](https://img.shields.io/badge/ImGui-009DFF?style=for-the-badge&logo=imgui&logoColor=white)](https://github.com/ocornut/imgui) 

A simple implementation of Flappy Bird in C++ and Raylib.

Based on my C++ Raylib Game Template: https://github.com/BenEklundCS/RaylibTemplate

---

## 🎮 Features

- ✅ **Flappy Bird Mechanics, jump over pipes - game exits if you collide!
- ✅ **Score counter, keeps track of your score as you traverse. How high can you go?
- ✅ **Smart Pipe spawning and deallocation as the object leaves the level

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
git clone https://github.com/BenEklundCS/FlappyBird.git
cd FlappyBird
```

### 2. Build the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
./FlappyBird   # or .\FlappyBird.exe on Windows
```
