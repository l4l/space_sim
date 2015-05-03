#include "Body.h"

phys::Body::Body(const std::string name, const phys::Vector speed,
                     const phys::Vector acceleration, double mass) :
        name(name), speed(speed), acceleration(acceleration),
        mass(mass) {}


phys::Body::Body(const std::string name, const phys::Vector speed,
                     const double mass) :
        Body(name, speed, Vector(), mass) {}


const phys::Vector phys::Body::updateSpeed(double dt) {
    phys::Vector t = speed;
    speed = speed + acceleration*dt;
    return t;
}

void phys::Body::increaseAcceleration(phys::Vector vector) {
    acceleration = acceleration + vector;
}
