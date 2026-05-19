#pragma once

#include "../math/Vec2.h"
#include "RigidBody.h"
#include <vector>

class World {
private:
    std::vector<Object*> m_objects;
    Vec2 gravity = Vec2{0, -9.81f};
public:
    void AddObject(Object *object);
    void RemoveObject(Object *object);
    void Step(float dt);
};