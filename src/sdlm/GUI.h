#ifndef _SM_H_
#define _SM_H_

#include <SDL.h>
#include <iostream>
#include <string>
#include "cleanUp.h"
#include "texHandl.h"
#include "World.h"

namespace sdlm {
    class GUI {
    private:
        bool         running;
        int            delay;
        SDL_Renderer* render;
        SDL_Window*   screen;

    public:
        GUI();
        GUI(int);

        bool initSDL();

        void event(SDL_Event*);

        void loop();
        int operator()(World*);


        static std::string getResourcePath(const std::string &);
        int prepare(std::string, int, int);
        int renderer();

    };
}

#endif