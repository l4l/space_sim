#ifndef SPACESIM_SERIALIZATOR_H
#define SPACESIM_SERIALIZATOR_H

#include "World.h"

std::ostream& operator<<(std::ostream&, Coordinate&);
std::istream& operator>>(std::istream&, Coordinate&);

std::ostream& operator<<(std::ostream&, phys::Vector&);
std::istream& operator>>(std::istream&, phys::Vector&);

std::ostream& operator<<(std::ostream&, phys::Body&);
std::istream& operator>>(std::istream&, phys::Body&);

std::ostream& operator<<(std::ostream&, World::Object&);
std::istream& operator>>(std::istream&, World::Object&);

std::ostream& operator<<(std::ostream&, World&);
std::istream& operator>>(std::istream&, World&);

#endif //SPACESIM_SERIALIZATOR_H