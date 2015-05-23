#ifndef GUI_H
#define GUI_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "cleanUp.h"
#include "handle.h"
#include "World.h"

namespace sdlm {
    class GUI {
    private:
        bool         running;
        unsigned int delay;
        SDL_Renderer* render;
        SDL_Window*   screen;

    public:
        GUI();
        GUI(unsigned int);

        bool initSDL();

        void event(SDL_Event*);

        void loop();
        int operator()(World);

        static std::string getResourcePath(const std::string &);
        int prepare(std::string, double, double);
        int renderer();

    };
}

#endif