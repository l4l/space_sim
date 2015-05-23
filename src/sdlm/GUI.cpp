#include "GUI.h"

sdlm::GUI::GUI() : delay(0), screen(nullptr), running(initSDL()) {}

sdlm::GUI::GUI(unsigned int dt) : delay(dt), screen(nullptr), running(initSDL()) {}

int sdlm::GUI::operator()(World w) {
    SDL_Event ev;
    std::vector<World::Object> objects;
    while(running) {
        objects = w.getObjects();

        while(SDL_PollEvent(&ev)) {
            event(&ev);
        }

        for(World::Object o: objects){
            prepare(o.getBody().getName(),
                    o.getCoord().getX(),
                    o.getCoord().getY());
        }

        renderer();
        SDL_Delay(delay);
        w.tick();
    }

    return 0;
}

