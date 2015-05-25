#include "GUI.h"

void sdlm::GUI::eventListener(SDL_Event *ev, World *w) {
    if(ev->type == SDL_QUIT) {
        running = false;
    }

    if(ev->type == SDL_DROPFILE){
        droppedDir = ev->drop.file;
        h->loadFromFile(droppedDir,w);
        SDL_free(droppedDir);
    }

    if (ev->type == SDL_KEYDOWN){
        switch (ev->key.keysym.sym){
            case SDLK_UP:
                delay!=0 ? (delay-0.5) : (delay);
                break;
            case SDLK_RIGHT:
                delay!=0 ? (delay-0.5) : (delay);
                break;
            case SDLK_DOWN:
                delay+=0.5;
                break;
            case SDLK_LEFT:
                delay+=0.5;
                break;
            case SDLK_ESCAPE:
                SDL_SetWindowFullscreen( screen, SDL_FALSE );
                break;
            default:
                running = false;
        }
        //running = false;
    }
    if (ev->type == SDL_MOUSEBUTTONDOWN){
        h->clickCreator(w);
    }
}
