#pragma once

#include "../math/Vec2.h"
#include <iostream>

// axis aligned bounding boxes
enum class ShapeType
{
    Circle,
    AABB
};

struct Shape
{
    ShapeType type;
    Shape(Shapetype type)
    : type(type) {}

    virtual ~Shape() = default;
};

struct AABB : Shape
{
    Vec2 halfSize;
    AABB(Vec2 halfSize)
        : Shape(ShapeType::Circle), halfSize(halfSize) {}
};

struct Circle : Shape
{
    float radius;
    Circle(float radius)
    : Shape(ShapeType::Circle), radius(radius) {}
};
