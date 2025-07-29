#include <imgui.h>
#include <string>
#include <vector>
#include <iostream>

#include "raylib.h"
#include "rlImGui.h"

// include
#include "Pipe.h"
#include "../include/Object.h"
#include "../include/Globals.h"
#include "../include/Bird.h"

typedef struct Game {
    Bird* bird{};
    std::vector<Object*> gameObjects;
    float pipeSpawnTimer;
    int gameScore;
} Game;

void InitWindow() {
    // create and set up window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_NAME);
    InitAudioDevice();
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(TARGET_FPS);
    SetExitKey(EXIT_KEY);
    rlImGuiSetup(true);
}

Game* InitGame() {
    // load game
    const auto game = new Game();
    // initialize bird
    const auto bird = new Bird(SPAWN_POSITION);
    game->bird = bird;

    game->pipeSpawnTimer = 1.0f;
    game->gameScore = 0;

    const auto pipe1 = new Pipe(Vector2{SCREEN_WIDTH, 0}, Vector2{PIPE_WIDTH, SCREEN_HEIGHT/2});
    game->gameObjects.push_back(pipe1);
    return game;
}

Game* Init() {
    InitWindow();
    return InitGame();
}

void CleanupGame(Game* game) {
    // delete all game objects
    for (const Object* o : game->gameObjects) {
        delete o;
    }
    // delete bird
    delete game->bird;
    // delete game structure
    delete game;
    // close the window
    CloseWindow();
}

void HandleInput(Game* game) {
    if (IsKeyPressed(KEY_UP)) {
        game->bird->Jump();
    }
}

void SpawnPipe(Game* game, float deltaTime) {
    if (game->pipeSpawnTimer <= 0.0f) {
        game->gameScore++;

        const float minPipeHeight = PIPE_WIDTH;
        const float maxPipeHeight = SCREEN_HEIGHT - PIPE_GAP - minPipeHeight;

        float topHeight = minPipeHeight + static_cast<float>(GetRandomValue(0, static_cast<int>(maxPipeHeight - minPipeHeight)));
        float bottomHeight = SCREEN_HEIGHT - topHeight - PIPE_GAP;

        // Top pipe
        Pipe* topPipe = new Pipe(
            {SCREEN_WIDTH, 0.0f},
            {PIPE_WIDTH, topHeight}
        );

        // Bottom pipe
        Pipe* bottomPipe = new Pipe(
            {SCREEN_WIDTH, topHeight + PIPE_GAP},
            {PIPE_WIDTH, bottomHeight}
        );

        game->gameObjects.push_back(topPipe);
        game->gameObjects.push_back(bottomPipe);

        game->pipeSpawnTimer = 1.0f;
    } else {
        game->pipeSpawnTimer -= deltaTime;
    }
}



void Update(Game* game) {
    // get frame time
    float deltaTime = GetFrameTime();
    // maybe spawn pipe
    SpawnPipe(game, deltaTime);
    // update
    game->bird->Update(deltaTime);
    for (int i = static_cast<int>(game->gameObjects.size()) - 1; i >= 0; --i) {
        Object* o = game->gameObjects[i];

        if (CheckCollisionRecs(game->bird->rect, o->rect)) {
            CleanupGame(game);
        }

        o->Update(deltaTime);

        if (Outside(o)) {
            delete o;
            game->gameObjects.erase(game->gameObjects.begin() + i);
        }
    }
}

void Draw(Game* game) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Corners
    // top left
    DrawCircle(0, 0, 10, RED);
    // bottom left
    DrawCircle(0, SCREEN_HEIGHT, 10, GREEN);
    // top right
    DrawCircle(SCREEN_WIDTH, 0, 10, BLUE);
    // bottom right
    DrawCircle(SCREEN_WIDTH, SCREEN_HEIGHT, 10, PURPLE);

    DrawText(std::to_string(game->gameScore).c_str(), SCREEN_WIDTH - 100, 10, 24, GREEN);

    // draw game
    game->bird->Draw();
    for (Object* o : game->gameObjects) {
        o->Draw();
    }

    EndDrawing();
}

int main() {
    Game* game = Init();
    while (!WindowShouldClose()) {
        HandleInput(game);
        Update(game);
        Draw(game);
    }
    CleanupGame(game);
    return 0;
}
