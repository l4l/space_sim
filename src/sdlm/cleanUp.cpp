#include "cleanUp.h"
template<>
void cleanup(SDL_Window *win) {
    if (!win){
        return;
    }
    SDL_DestroyWindow(win);
}

template<>
void cleanup(SDL_Renderer *ren) {
    if (!ren){
        return;
    }
    SDL_DestroyRenderer(ren);
}

template<>
void cleanup(SDL_Texture *tex) {
    if (!tex){
        return;
    }
    SDL_DestroyTexture(tex);
}

template<>
void cleanup(SDL_Surface *surf) {
    if (!surf){
        return;
    }
    SDL_FreeSurface(surf);
}
