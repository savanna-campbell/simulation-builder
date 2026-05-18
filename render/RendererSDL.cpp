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

int Renderer::drawCircle(const Circle& circle){
    if(renderer==nullptr) {
        return -1;
    }
    // use midpoint circle algorithm
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = circle.radius;
    d = circle.radius - 1;
    status = 0;
    while (offsety >= offsetx)
    {
        status += SDL_RenderDrawPoint(renderer, circle.x + offsetx, circle.y + offsety);
        status += SDL_RenderDrawPoint(renderer, circle.x + offsety, circle.y + offsetx);
        status += SDL_RenderDrawPoint(renderer, circle.x - offsetx, circle.y + offsety);
        status += SDL_RenderDrawPoint(renderer, circle.x - offsety, circle.y + offsetx);
        status += SDL_RenderDrawPoint(renderer, circle.x + offsetx, circle.y - offsety);
        status += SDL_RenderDrawPoint(renderer, circle.x + offsety, circle.y - offsetx);
        status += SDL_RenderDrawPoint(renderer, circle.x - offsetx, circle.y - offsety);
        status += SDL_RenderDrawPoint(renderer, circle.x - offsety, circle.y - offsetx);
        
        if (status < 0) {
            status = -1;
            break;
        }

        if(d >= 2*offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (circle.radius - offsety)) {
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

int Renderer::fillCircle(const Circle& circle) {
    if(renderer==nullptr) {
        return -1;
    }
    int offsetx, offsety, d;
    int status;
    offsetx = 0;
    offsety = circle.radius;
    d = circle.radius - 1;
    status = 0;

    while (offsety >= offsetx)
    {
        status += SDL_RenderDrawLine(renderer, circle.x - offsety, circle.y + offsetx,
                                        circle.x + offsety, circle.y + offsetx);
        status += SDL_RenderDrawLine(renderer, circle.x - offsetx, circle.y + offsety,
                                        circle.x + offsetx, circle.y + offsety);
        status += SDL_RenderDrawLine(renderer, circle.x - offsety, circle.y - offsetx,
                                        circle.x + offsety, circle.y - offsetx);
        status += SDL_RenderDrawLine(renderer, circle.x - offsetx, circle.y - offsety,
                                        circle.x + offsetx, circle.y - offsety);
        
        if (status < 0) {
            status = -1;
            break;
        }
        

        if(d >= 2*offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (circle.radius - offsety)) {
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

void Renderer::drawAABB(const AABB& aabb) {
    if(renderer==nullptr) {
        return;
    }
    SDL_Rect rect {
        static_cast<int>(aabb.min.x),
        static_cast<int>(aabb.min.y),
        static_cast<int>(aabb.max.x - aabb.min.x),
        static_cast<int>(aabb.max.y - aabb.min.y)
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

SDL_Renderer* getRenderer(){
    return renderer;
}
