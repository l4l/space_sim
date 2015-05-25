#ifndef _SURFACEM_H_
#define _SURFACEM_H_

#include "GUI.h"

namespace sdlm {
    class texHandl {
    public:
        texHandl();

    public:
        static void logSDLError(std::ostream&, const std::string&);
        static SDL_Texture* LoadTexture(std::string, SDL_Renderer*);
        static void RenderTexture(const std::string&, SDL_Renderer*, int, int);
    };
}
#endif