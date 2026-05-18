#include <SDL/SDL.h>
#include <iostream>
#include <string>

class Window {
    SDL_Window *window = nullptr;
    int HEIGHT;
    int WIDTH;
    std::string TITLE;

public:
    Window(int _HEIGHT, int _WIDTH, std::string _TITLE)
        :HEIGHT(_HEIGHT), WIDTH(_WIDTH), TITLE(_TITLE)
        {
            createWindow();
        }

    ~Window(){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Window* getWindow() const {
        return window;
    }
    int getHeight() const {
        return HEIGHT;
    }
    int getWidth() const {
        return WIDTH;
    }
private:
    void createWindow() {
        
        window = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){
            printf("window could not be created. Error: %s\n", SDL_GetError());
        }
        
        
    }
};