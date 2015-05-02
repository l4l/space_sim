#include "Coordinate.h"
#include "math.h"

Coordinate::Coordinate() :
        Coordinate(0, 0) {}

Coordinate::Coordinate(double x, double y) :
        x(x), y(y) {}

Coordinate::Coordinate(const Coordinate c, double r, double x) :
        x(x), y(c.y + sqrt(r*r-(x - c.x)*(x - c.x))) {}

inline static double distance(const double x0, const double y0,
                              const double x1, const double y1) {
    return sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
}

double Coordinate::getDistance(const Coordinate coordinate) const {
    return distance(this->x, this->y, coordinate.x, coordinate.y);
}

void Coordinate::move(double dx, double dy) {
    this->x += dx;
    this->y += dy;
}
