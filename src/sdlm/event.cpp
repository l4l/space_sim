#include "GUI.h"

void sdlm::GUI::event(SDL_Event *ev) {
    if(ev->type == SDL_QUIT) {
        running = false;
    }
    if (ev->type == SDL_QUIT){
        running = false;
    }
    if (ev->type == SDL_KEYDOWN){
        switch (ev->key.keysym.sym){
            case SDLK_UP:
                delay!=0 ? (delay-=100) : (delay+=100);
                break;
            case SDLK_RIGHT:
                delay!=0 ? (delay-=100) : (delay+=100);
                break;
            case SDLK_DOWN:
                delay++;
                break;
            case SDLK_LEFT:
                delay++;
                break;
            default:
                running = false;
        }
        running = false;
    }
    if (ev->type == SDL_MOUSEBUTTONDOWN){
        running = false;
    }
}