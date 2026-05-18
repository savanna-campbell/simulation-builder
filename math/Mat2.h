#pragma once
#include <cmath>
#include "Vec2.h"

struct Mat2 {
    float a1, a2;
    float b1, b2;

    Vec2 operator*(const Vec2& Other) const{
        return Vec2{
            a1 * Other.x + a2 * Other.y,
            b1 * Other.x + b2 * Other.y};
    }
    Mat2 operator*(const Mat2& Other) const{
        return Mat2{
            a1 * Other.a1 + a2 * Other.b1,
            a1 * Other.a2 + a2 * Other.b2,
            b1 * Other.a1 + b2 * Other.b1,
            b1 * Other.a2 + b2 * Other.b2,
        };
    }
    Mat2 operator*(const float scalar) const {
        return Mat2{
            a1 * scalar, 
            a2 * scalar, 
            b1 * scalar, 
            b2 * scalar};
    }
    static Mat2 identity() {
        return Mat2{
            1, 0, 
            0, 1};
    }
    static Mat2 rotation(float radians){
        float c = std::cos(radians);
        float s = std::sin(radians);
        return Mat2{
            c, -s, 
            s, c};
    }
};