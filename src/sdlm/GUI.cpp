#include "GUI.h"

sdlm::GUI::GUI():delay(0), screen(NULL),
                 render(NULL), running(initSDL()){}

sdlm::GUI::GUI(int dt):delay(dt), screen(NULL),
                        render(NULL), running(initSDL()) {}

int sdlm::GUI::operator()(World* w) {
    SDL_Event ev;
    const std::vector<World::Object> objects = w->getObjects();
    while(running) {

        while(SDL_WaitEvent(&ev)) {
            event(&ev);
        }

        for(auto n : objects){
            prepare(n.getBody().getName(), n.getCoord().getX(), n.getCoord().getY());
        }

        renderer();
        w->tick();
    }

    cleanup(render);

    return 0;
}

