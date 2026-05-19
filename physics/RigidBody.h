#pragma once

#include "../math/Vec2.h"
#include "Shapes.h"

struct Object {    
    Vec2 position;
    Vec2 velocity;
    Vec2 force;
    
    Shape* shape;
    
    float angle = 0.0f; // radians
    float angularVelocity = 0.0f;
    float torque = 0.0f;

    float mass = 2.0f;
    float inverseMass = 0.5f;

    float momentOfInertia = 1.0f;
    float inverseInertia = 1.0f;
};