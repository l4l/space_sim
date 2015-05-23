#include "GUI.h"

int sdlm::GUI::prepare(std::string name, double x, double y){
        sdlm::handle::RenderTexture(name, render, x, y);
    //TODO: check return
}

int sdlm::GUI::renderer(){
    SDL_RenderPresent(render);
    SDL_Delay(delay);
    SDL_RenderClear(render);
}