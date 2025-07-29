#include "../include/Bird.h"

void Bird::Update(const float deltaTime) {
    // adjust velocity y based on gravity
    velocity.y += GRAVITY * deltaTime;
    // move the object based on velocity
    MoveObject(this, Vector2{rect.x + velocity.x, rect.y + velocity.y}, true);
}

void Bird::Draw() {
    // Draw a red square at the center
    DrawRectangle(
        rect.x,
        rect.y,
        rect.width,
        rect.height,
        MAGENTA
    );
}

void Bird::Jump() {
    velocity.y = -jumpVelocity;
}


