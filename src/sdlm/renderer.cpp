#include "GUI.h"

int sdlm::GUI::renderer(){
    SDL_RenderPresent(render);
    SDL_Delay(delay);
    SDL_RenderClear(render);
}
