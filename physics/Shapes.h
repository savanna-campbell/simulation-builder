#pragma once

#include "../math/Vec2.h"
#include <iostream>

// axis aligned bounding boxes
struct Shape {
    virtual ~Shape() = default;
};

struct AABB : Shape
{
    Vec2 halfSize;
    AABB(Vec2 halfSize)
        : halfSize(halfSize) {}
};

struct Circle : Shape
{
    float radius;
    Circle(float radius)
    : radius(radius) {}
};
