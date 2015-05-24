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
        unsigned int   delay;

        SDL_Renderer* render;
        SDL_Window*   screen;
        SDL_Texture*     tex;
        SDL_Rect         dst;

        World*         world;

    public:
        GUI();
        GUI(unsigned int);

        bool initSDL();
        void initTexture();
        void prepare(std::string const, double, double);

        void loop();
        void event(SDL_Event*);
        int operator()(World*);

        static std::string getResourcePath(const std::string &);
        int renderer();

    };
}

#endif
