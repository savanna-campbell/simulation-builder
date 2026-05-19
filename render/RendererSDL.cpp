#include "RendererSDL.h"
#include <iostream>

Renderer::Renderer(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        printf("Renderer could not be created %s\n", SDL_GetError());
    }
    else{
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
}
Renderer::~Renderer(){
    if(renderer != nullptr){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}

void Renderer::drawObj(const Object* obj) {
    if (obj == nullptr){
        return;
    }
    if(Circle* circle = dynamic_cast<Circle*>(obj->shape)) {
        drawCircle(obj->position, circle->radius);
    }
    if(AABB* aabb = dynamic_cast<AABB*>(obj->shape)) {
        drawAABB(obj->position, aabb->halfSize);
    }
}

int Renderer::drawCircle(const Vec2& position, float r){
    if(renderer==nullptr) {
        return -1;
    }
    // use midpoint circle algorithm

    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y);
    int radius = static_cast<int>(r);
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;
    while (offsety >= offsetx)
    {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);
        
        if (status < 0) {
            status = -1;
            break;
        }

        if(d >= 2*offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2*(offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
    return status;
}

int Renderer::fillCircle(const Vec2& position, float r) {
    if(renderer==nullptr) {
        return -1;
    }
    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y);
    int radius = static_cast<int>(r);

    int offsetx, offsety, d;
    int status;
    
    offsetx = 0;
    offsety = radius;
    
    d = radius - 1;
    
    status = 0;

    while (offsety >= offsetx)
    {
        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                        x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                        x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                        x + offsety, y - offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                        x + offsetx, y - offsety);
        
        if (status < 0) {
            status = -1;
            break;
        }
        

        if(d >= 2*offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2*(offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
    return status;
}

void Renderer::drawAABB(const Vec2& position, const Vec2& halfsize) {
    if(renderer==nullptr) {
        return;
    }
    SDL_Rect rect {
        static_cast<int>(position.x - halfsize.x),
        static_cast<int>(position.y - halfsize.y),
        static_cast<int>(2 * halfsize.x),
        static_cast<int>(2 * halfsize.y)
    };
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::clear(){
    if(renderer==nullptr) {
        return;
    }
    SDL_RenderClear(renderer);
}

void Renderer::present(){
    if(renderer==nullptr) {
        return;
    }
    SDL_RenderPresent(renderer);
}

void Renderer::setDrawColor(int R, int G, int B, int A){
    if(renderer==nullptr) {
        return;
    }
    SDL_SetRenderDrawColor(renderer, R, G, B, A);
}

SDL_Renderer* Renderer::getRenderer(){
    return renderer;
}
