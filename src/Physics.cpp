#include "../include/Physics.h"
#include <algorithm>  // std::clamp

/**
 * Moves an object to a new position, and validates the move is valid before performing it with std::clamp
 * @param object The object we are moving
 * @param newPosition The desired new position of the object
 */
void MoveObject(Object* object, Vector2 newPosition, bool bounded) {
    if (bounded) {
        // clamp the new position within the bounds of the screen
        newPosition.x = std::clamp(newPosition.x, 0.0f,
                              SCREEN_WIDTH  - object->rect.width);
        newPosition.y = std::clamp(newPosition.y, 0.0f,
                              SCREEN_HEIGHT - object->rect.height);
    }
    // set the new position
    object->rect.x = newPosition.x;
    object->rect.y = newPosition.y;
}

bool PointBetween(Vector2 pointA, Vector2 pointB) {
    
}

bool Outside(const Object *object) {
    const bool outsideX = object->rect.x + object->rect.width < 0 || object->rect.x > SCREEN_WIDTH;
    const bool outsideY = object->rect.y + object->rect.height < 0 || object->rect.y > SCREEN_HEIGHT;
    return (outsideX | outsideY);
}




