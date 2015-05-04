#ifndef SPACESIM_BODY_H
#define SPACESIM_BODY_H

#include "string"
#include "Coordinate.h"
#include "Vector.h"

namespace phys
{

class Body {

public:
    const phys::Vector updateSpeed(double);

    void increaseAcceleration(phys::Vector);

    Body(const std::string, const phys::Vector, const double);
    Body(const std::string, const phys::Vector,
           const phys::Vector, const double);

    const std::string getName() const {
        return name;
    }

    double getMass() const {
        return mass;
    }

private:
    const std::string name;

    phys::Vector speed;

    phys::Vector acc;

    double mass;
};

}
#endif //SPACESIM_PLANET_H
