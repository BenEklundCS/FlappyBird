#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

// game primitives
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr auto SCREEN_NAME = "Jumpy Bird";
constexpr int TARGET_FPS = 60;
constexpr int EXIT_KEY = 0;

// physics
constexpr float GRAVITY = 75.0f;
constexpr float GAME_SPEED = 10.f;

// settings

// player spawn position
constexpr auto SPAWN_POSITION = Vector2{SCREEN_WIDTH/4.0f, SCREEN_HEIGHT/2.0f};

// pipes
constexpr auto PIPE_WIDTH = 50.0f;
constexpr auto PIPE_GAP = 200.0f;

#endif //GLOBALS_H
