#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include "cleanUp.h"
#include "handle.h"

namespace sdlm {
    class GUI {
    private:
        bool         running;
        unsigned int   delay;
        char*    droppedDir;
        SDL_Renderer* render;

        SDL_Window*   screen;
        SDL_Texture*     tex;
        SDL_Rect         dst;

        handle*            h;

    public:
        GUI();
        GUI(unsigned int);

        bool initSDL();
        void initTexture();
        void prepare(std::string const, double, double);

        void loop();
        void eventListener(SDL_Event *ev, World *w);
        int operator()(World*);

        static std::string getResourcePath(const std::string &);

        int renderer();
    };
}

#endif
