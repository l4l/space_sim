#ifndef SPACESIM_VECTOR_H
#define SPACESIM_VECTOR_H

#include "Coordinate.h"

namespace phys
{

class Vector {
public:
    Vector();
    Vector(double, double, double);
    Vector(const Coordinate&);

    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector operator*(double) const;
    Vector operator/(double) const;
    Vector operator=(Vector);

    void normalize();

    double length() const;

    const Coordinate getEnd() const {
        return end;
    }

protected:
    Coordinate end;
};

}

#endif //SPACESIM_VECTOR_H
