#ifndef BIRD_H
#define BIRD_H

#include "Object.h"

class Bird final : public Object {
private:
    float jumpVelocity = GRAVITY * 0.26f;
    Vector2 birdSize = Vector2{25.0f, 25.0f};
public:
    explicit Bird(const Vector2 position) {
        this->rect = Rectangle{position.x, position.y, birdSize.x, birdSize.y};
        this->velocity = Vector2{0.0f, 0.0f};
    }
    void Update(float deltaTime) override;
    void Draw() override;
    void Jump();
};

#endif //BIRD_H
