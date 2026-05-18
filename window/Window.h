#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Window {

private:
    SDL_Window *window = nullptr;
    int HEIGHT;
    int WIDTH;
    std::string TITLE;

public:
    Window(int _HEIGHT, int _WIDTH, std::string _TITLE);

    ~Window();
    SDL_Window *getWindow() const;
    int getHeight() const;
    int getWidth() const;

private:
    void createWindow();
};