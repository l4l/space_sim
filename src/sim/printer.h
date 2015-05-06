#ifndef SPACESIM_PRINTER_H
#define SPACESIM_PRINTER_H

#include "World.h"
#include "consts.h"

std::string help();

std::string print(Coordinate&);
std::string print(phys::Vector&);
std::string print(phys::Body&);
std::string print(World::Object&);
std::string print(World&);

#endif //SPACESIM_PRINTER_H
