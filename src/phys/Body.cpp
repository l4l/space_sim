#include "Body.h"

phys::Body::Body(const std::string name, const phys::Vector speed,
                     const phys::Vector acc, double mass) :
        name(name), speed(speed),
        acc(acc), mass(mass) {}

phys::Body::Body(const std::string name, const phys::Vector speed,
                     const double mass) :
        Body(name, speed, Vector(), mass) {}

phys::Body::Body(const phys::Body &body) :
        name(body.getName()), speed(body.getSpeed()),
        acc(body.getAcc()), mass(body.getMass()){}

phys::Body phys::Body::operator=(phys::Body body) {
    return phys::Body(body);
}

const phys::Vector phys::Body::updateSpeed(double dt) {
    phys::Vector t = speed;
    speed = speed + acc *dt;
    return t;
}

void phys::Body::increaseAcceleration(phys::Vector vector) {
    acc = acc + vector;
}
