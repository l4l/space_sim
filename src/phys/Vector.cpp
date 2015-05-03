#include "Vector.h"

phys::Vector::Vector() : Vector(0, 0) {}

phys::Vector::Vector(double x, double y) : Vector(Coordinate(x, y)) {}

phys::Vector::Vector(const Coordinate &coordinate) : end(coordinate) {}

phys::Vector phys::Vector::operator+(const phys::Vector &vector) const {
    return phys::Vector(this->end.getX() + vector.end.getX(),
                        this->end.getY() + vector.end.getY());
}

phys::Vector phys::Vector::operator*(double size) const {
    return phys::Vector(end.getX()*size,
                        end.getY()*size);
}

phys::Vector phys::Vector::operator/(double size) const {
    return phys::Vector(end.getX()/size,
                        end.getY()/size);
}

void phys::Vector::normalize() {
    *this = *this/length();
}

double phys::Vector::length() const {
    return end.getDistance();
}
