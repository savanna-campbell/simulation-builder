#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../physics/Shapes.h"

class Renderer {
    private:
    SDL_Renderer *renderer = nullptr;
    public:
    explicit Renderer(SDL_Window *window);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    int drawCircle(const Circle &circle);
    int fillCircle(const Circle &circle);

    void drawAABB(const AABB &aabb);

    void clear();

    void present();

    void setDrawColor(int R, int G, int B, int A);

    SDL_Renderer *getRenderer();
};