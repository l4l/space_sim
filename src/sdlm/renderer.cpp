#include "GUI.h"

int sdlm::GUI::prepare(std::string name, int X, int Y){
        SDL_RenderClear(render);
        sdlm::texHandl::RenderTexture(name, render, X, Y);
}

int sdlm::GUI::renderer(){
    SDL_RenderPresent(render);
    SDL_Delay(delay);
}