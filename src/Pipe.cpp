#include "../include/Pipe.h"

void Pipe::Update(float deltaTime) {
    MoveObject(this, Vector2{rect.x + velocity.x, rect.y + velocity.y}, false);
}

void Pipe::Draw() {
    DrawRectangle(
        rect.x,
        rect.y,
        rect.width,
        rect.height,
        BLACK
    );
}