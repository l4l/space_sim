#include "string"
#include "Coordinate.h"
#include "Vector.h"
#ifndef SPACESIM_OBJECT_H
#define SPACESIM_OBJECT_H

namespace phys
{

class Object {

private:

    const std::string name;

    Coordinate coord;

    double speed;

    phys::Vector acceleration;

    long mass;




public:

};

}
#endif //SPACESIM_PLANET_H
