#pragma once
#include <cmath>

struct Vec2
{
    float x;
    float y;


    Vec2 operator+(const Vec2& Other) const {
        return Vec2 {
            x + Other.x,
            y + Other.y
        };
    }

    Vec2 operator-(const Vec2& Other) const {
        return Vec2{
            x - Other.x,
            y - Other.y};
    }

    Vec2 operator*(float Multiplier) const {
        return Vec2{
            x * Multiplier,
            y * Multiplier};
    }
    Vec2 operator/(float Divisor) const {
        if(Divisor == 0.0)
        {
            return Vec2{0, 0};
        }
        return Vec2{
            x / Divisor,
            y / Divisor};
    }
    Vec2& operator*=(float Multiplier)
    {
        x *= Multiplier;
        y *= Multiplier;
        return *this;
    }
    Vec2& operator/=(float Divisor) {
        if (Divisor == 0.0f){
            return *this;
        }
        x /= Divisor;
        y /= Divisor;
        return *this;
    }
    Vec2& operator+=(const Vec2 Other) {
        x += Other.x;
        y += Other.y;
        return *this;
    }

    float GetLength() const {
        return std::sqrt(x * x + y * y);
    }
    float GetDistance(const Vec2& Other) const {
        return std::sqrt(
            std::pow(x - Other.x, 2) +
            std::pow(y - Other.y, 2));
    }
};