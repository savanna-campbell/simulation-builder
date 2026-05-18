#include "Window.h"



Window::Window(int _HEIGHT, int _WIDTH, std::string _TITLE)
    :HEIGHT(_HEIGHT), WIDTH(_WIDTH), TITLE(_TITLE)
    {
        createWindow();
    }

Window::~Window(){
    SDL_DestroyWindow(window);
    window = nullptr;
}
SDL_Window* Window::getWindow() const {
    return window;
}
int Window::getHeight() const {
    return HEIGHT;
}
int Window::getWidth() const {
    return WIDTH;
}
void Window::createWindow() {
    
    window = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr){
        printf("window could not be created. Error: %s\n", SDL_GetError());
    }
    
    
}
