#ifndef SPACESIM_PRINTER_H
#define SPACESIM_PRINTER_H

#include "World.h"
#include "consts.h"

std::string help();

std::string print(const Coordinate&);
std::string print(const phys::Vector&);
std::string print(const phys::Body&);
std::string print(const World::Object&);
std::string print(const World&);

#endif //SPACESIM_PRINTER_H
