#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

#include <Alchemist/Config.h>
#include <Alchemist/Core/Log.h>

static tt::Logger LOGGER = tt::Logger::create("Alchemist");

int TTAPI Alchemist_Main()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
        return -1;

    SDL_Window *window = SDL_CreateWindow("Test Application", 1920, 1080, 0);
    if (!window)
        return -2;

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDLK_ESCAPE)
                    running = false;
            }
        }
    }

    std::string value = "Test";
    LOGGER.log("Test");

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

#if ALCHEMIST_PLATFORM_WIN32
#include "Alchemist/Platform/Windows.cpp"
#endif
