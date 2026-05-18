#include "window/Window.h"
#include "render/RendererSDL.h"

Window *window = nullptr;
Renderer *renderer = nullptr;
bool init();
Circle circle{50, Vec2{400,200}};

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize. Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        window = new Window(400, 800, "Physics Engine");
        renderer = new Renderer(window->getWindow());
    }
    return success;
}

void close(){
    delete renderer;
    renderer = nullptr;

    delete window;
    window = nullptr;

    SDL_Quit();
}

int main(int argc, char* args[])
{
    
    if(!init()) {
        return false;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }
        renderer->setDrawColor(0, 0, 0, 255);
        renderer->clear();

        renderer->setDrawColor(255, 255, 255, 255);
        renderer->drawCircle(circle);
        renderer->fillCircle(circle);

        renderer->present();
    }

    close();
    return 0;
}