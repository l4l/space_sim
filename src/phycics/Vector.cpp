#include "Vector.h"

phys::Vector::Vector(double x, double y) :
        end(Coordinate(x, y)) {}

phys::Vector::Vector(const Coordinate &start, const Coordinate &end) :
        Vector(end.getX(), start.getX(), end.getY(), start.getY()) {}

phys::Vector::Vector(double x0, double y0, double x1, double y1) :
        Vector(x1-x0, y1-y0) {}

phys::Vector phys::Vector::operator+(const phys::Vector &v) {
    return Vector(this->end.getX() + v.end.getX(),
                  this->end.getY() + v.end.getY());
}

double phys::Vector::length() const {
    return distance(end.getX(), end.getY(), 0, 0);
}
