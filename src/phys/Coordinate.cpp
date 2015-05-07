#include "Coordinate.h"
#include "math.h"

Coordinate::Coordinate() :
        Coordinate(0, 0, 0) {}

Coordinate::Coordinate(const Coordinate &coord) :
        Coordinate(coord.getX(),
                   coord.getY(),
                   coord.getZ()) {}

Coordinate::Coordinate(double x, double y, double z) :
        x(x), y(y), z(z) {}

void Coordinate::move(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

inline static double distance(const double x0, const double y0,  const double z0,
                              const double x1, const double y1, const double z1) {
    return sqrt(SQR(x0-x1) + SQR(y0-y1) + SQR(z0-z1));
}

double Coordinate::getDistance() const {
    return distance(x, y, z, 0, 0, 0);
}

double Coordinate::getDistance(const Coordinate coord) const {
    return distance(x, y, z, coord.x, coord.y, coord.z);
}

Coordinate Coordinate::operator=(Coordinate coordinate) {
    return Coordinate(coordinate);
}
