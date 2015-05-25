#ifndef _SURFACEM_H_
#define _SURFACEM_H_


#include <SDL.h>
#include "World.h"
#include "serializator.h"
#include "fstream"

namespace sdlm {
    class handle {
    public:
        handle();

    public:
        void logSDLError(std::ostream&, const std::string&);
        void loadFromFile(const char*, World*);
        void clickCreator(World*);
    };
}
#endif
