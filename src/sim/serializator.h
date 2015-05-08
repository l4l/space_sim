#ifndef SPACESIM_SERIALIZATOR_H
#define SPACESIM_SERIALIZATOR_H

#include "World.h"

std::ostream& operator<<(std::ostream&, const Coordinate&);
std::istream& operator>>(std::istream&, Coordinate&);

std::ostream& operator<<(std::ostream&, const phys::Vector&);
std::istream& operator>>(std::istream&, phys::Vector&);

std::ostream& operator<<(std::ostream&, const phys::Body&);
std::istream& operator>>(std::istream&, phys::Body&);

std::ostream& operator<<(std::ostream&, const World::Object&);
std::istream& operator>>(std::istream&, World::Object&);

std::ostream& operator<<(std::ostream&, const World&);
std::istream& operator>>(std::istream&, World&);

#endif //SPACESIM_SERIALIZATOR_H