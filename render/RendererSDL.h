#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../physics/Shapes.h"
#include "../physics/RigidBody.h"


class Renderer {
    private:
    SDL_Renderer *renderer = nullptr;
    public:
    explicit Renderer(SDL_Window *window);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    void drawObj(const Object *obj);

    int drawCircle(const Vec2& position, float r);
    int fillCircle(const Vec2& position, float r);

    void drawAABB(const Vec2& position, const Vec2& halfsize);

    void clear();

    void present();

    void setDrawColor(int R, int G, int B, int A);

    SDL_Renderer *getRenderer();
};