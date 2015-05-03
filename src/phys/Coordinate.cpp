#include "Coordinate.h"
#include "math.h"

Coordinate::Coordinate() :
        Coordinate(0, 0) {}

Coordinate::Coordinate(const Coordinate &coord) :
        Coordinate(coord.getX(), coord.getY()) {}

Coordinate::Coordinate(double x, double y) :
        x(x), y(y) {}

Coordinate::Coordinate(const Coordinate c, double r, double x) :
        x(x), y(c.y + sqrt(r*r-(x - c.x)*(x - c.x))) {}

void Coordinate::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Coordinate::invert() {
    x *= -1;
    y *= -1;
}

inline static double distance(const double x0, const double y0,
                              const double x1, const double y1) {
    return sqrt(SQR(x0-x1) + SQR(y0-y1));
}

double Coordinate::getDistance() const {
    return distance(x, y, 0, 0);
}

double Coordinate::getDistance(const Coordinate coord) const {
    return distance(x, y, coord.x, coord.y);
}
