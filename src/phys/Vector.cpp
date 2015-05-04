#include "Vector.h"

phys::Vector::Vector() : Vector(0, 0, 0) {}

phys::Vector::Vector(double x, double y, double z) :
        Vector(Coordinate(x, y, z)) {}

phys::Vector::Vector(const Coordinate &coordinate) :
        end(coordinate) {}

phys::Vector phys::Vector::operator+(const phys::Vector &vector) const {
    return phys::Vector(end.getX() + vector.end.getX(),
                        end.getY() + vector.end.getY(),
                        end.getZ() + vector.end.getZ());
}

phys::Vector phys::Vector::operator-(const phys::Vector &vector) const {
    return phys::Vector(end.getX() - vector.end.getX(),
                        end.getY() - vector.end.getY(),
                        end.getZ() - vector.end.getZ());
}

phys::Vector phys::Vector::operator*(double size) const {
    return phys::Vector(end.getX()*size,
                        end.getY()*size,
                        end.getZ()*size);
}

phys::Vector phys::Vector::operator/(double size) const {
    return phys::Vector(end.getX()/size,
                        end.getY()/size,
                        end.getZ()/size);
}

void phys::Vector::normalize() {
    *this = *this/length();
}

double phys::Vector::length() const {
    return end.getDistance();
}
