#ifndef OBJECT_H
#define OBJECT_H
#include "raylib.h"
#include "Globals.h"
#include "Physics.h"

class Object {
private:
public:
    Vector2 velocity{};
    Rectangle rect;
    Object() = default;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual ~Object() = default;
};

#endif //OBJECT_H
