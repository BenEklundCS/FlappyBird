#ifndef PHYSICS_H
#define PHYSICS_H

#include "Object.h"
#include "Globals.h"
class Object;

void MoveObject(Object* object, Vector2 newPosition, bool bounded);
bool Outside(const Object* object);

#endif //PHYSICS_H
