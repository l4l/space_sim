#ifndef SPACESIM_VECTOR_H
#define SPACESIM_VECTOR_H

#include "Coordinate.h"

namespace phys
{

class Vector {
protected:
    Coordinate end;

public:
    Vector();

    Vector(double, double);

    Vector(const Coordinate&);

    Vector operator+(const Vector&) const;

    Vector operator*(double) const;

    Vector operator/(double) const;

    void normalize();

    double length() const;

    const Coordinate getEnd() const {
        return end;
    }
};

}

#endif //SPACESIM_VECTOR_H
