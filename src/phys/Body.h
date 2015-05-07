#ifndef SPACESIM_BODY_H
#define SPACESIM_BODY_H

#include "string"
#include "Coordinate.h"
#include "Vector.h"

namespace phys
{

class Body {

public:
    Body(const std::string, const phys::Vector, const double);
    Body(const Body&);

    Body operator=(Body);

    const phys::Vector updateSpeed(phys::Vector);

    const std::string getName() const {
        return name;
    }

    double getMass() const {
        return mass;
    }

    const Vector &getSpeed() const {
        return speed;
    }

private:
    const std::string name;

    phys::Vector speed;

    double mass;
};

}
#endif //SPACESIM_PLANET_H
