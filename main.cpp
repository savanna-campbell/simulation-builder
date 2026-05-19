#define MAXIMUM_FRAME_RATE 120
#define MINIMUM_FRAME_RATE 15
#define UPDATE_INTERVAL (1.0 / MAXIMUM_FRAME_RATE)
#define MAX_CYCLES_PER_FRAME (MAXIMUM_FRAME_RATE / MINIMUM_FRAME_RATE)

#include "window/Window.h"
#include "render/RendererSDL.h"
#include "physics/World.h"


// load in window and renderer 
Window *window = nullptr;
Renderer *renderer = nullptr;
World world;

// test object
Circle circle{50};
Object* ball = new Object{Vec2{400,200}, Vec2{0,0}, Vec2{0,0}, &circle};


double GetCurrentTime(){
    static Uint64 frequency = SDL_GetPerformanceFrequency();
    Uint64 counter = SDL_GetPerformanceCounter();

    return static_cast<double>(counter) / static_cast<double>(frequency);
}

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
        return 0;
    }
    
    static double lastFrameTime = GetCurrentTime();
    static double cyclesLeftOver = 0.0;
    double currentTime;
    double updateIterations;

    // set up test object
    world.AddObject(ball);
    

    

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }


        currentTime = GetCurrentTime();
        updateIterations = (currentTime - lastFrameTime) + cyclesLeftOver;
        
        if (updateIterations > MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL) {
            updateIterations = MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL;
        }
        while(updateIterations > UPDATE_INTERVAL) {
            updateIterations -= UPDATE_INTERVAL;
            world.Step(UPDATE_INTERVAL);
        }
        cyclesLeftOver = updateIterations;
        lastFrameTime = currentTime;

        renderer->setDrawColor(0, 0, 0, 255);
        renderer->clear();

        renderer->setDrawColor(255, 255, 255, 255);
        renderer->drawObj(ball);

        renderer->present();
    }

    close();
    return 0;
}