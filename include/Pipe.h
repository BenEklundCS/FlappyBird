#ifndef PIPE_H
#define PIPE_H

#include "Object.h"

class Pipe final : public Object {
private:
public:
    Pipe(const Vector2 position, const Vector2 dimensions) {
        this->rect = Rectangle{position.x, position.y, dimensions.x, dimensions.y};
        this->velocity = Vector2{-GAME_SPEED, 0.0f};
    }
    void Update(float deltaTime) override;
    void Draw() override;
};

#endif //PIPE_H
