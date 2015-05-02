#include "Coordinate.h"

#ifndef SPACESIM_VECTOR_H
#define SPACESIM_VECTOR_H

namespace phys
{

class Vector {
private:

    Coordinate end;

public:

    Vector(double, double);

    Vector(double, double, double, double);

    Vector(const Coordinate&, const Coordinate&);

    Vector operator+(const Vector& v);

    double length() const;
};

}
#endif //SPACESIM_VECTOR_H
