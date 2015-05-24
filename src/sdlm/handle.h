#ifndef _SURFACEM_H_
#define _SURFACEM_H_

#include "GUI.h"

namespace sdlm {
    class handle {
    public:
        handle();

    public:
        static void logSDLError(std::ostream&, const std::string&);
    };
}
#endif
