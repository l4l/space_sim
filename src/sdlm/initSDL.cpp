#include "GUI.h"

bool sdlm::GUI::initSDL() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        h->logSDLError(std::cout, "SDL_Init");
        return false;
    }

    if((screen = SDL_CreateWindow("Galaxy", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) == nullptr) {
        h->logSDLError(std::cout, "CreateWindow");
        cleanup(screen);
        SDL_Quit();
        return false;
    }

    render = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC);
    if (render == nullptr) {
        h->logSDLError(std::cout, "CreateRenderer");
        cleanup(render);
        SDL_Quit();
        return false;
    }

    // all good -> running == true;
    //sdlm::GUI::GUI();

    return true;
}
