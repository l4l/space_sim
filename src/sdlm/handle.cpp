#include <iostream>
#include "handle.h"


sdlm::handle::handle() {}


void sdlm::handle::logSDLError(std::ostream &os, const std::string &msg) {
    os<<msg<<" error: "<<SDL_GetError()<<std::endl;
}
