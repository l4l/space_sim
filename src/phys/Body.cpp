#include "Body.h"

phys::Body::Body(const std::string name, const phys::Vector speed, double mass) :
        name(name), speed(speed), mass(mass) {}

phys::Body::Body(const phys::Body &body) :
        name(body.getName()), speed(body.getSpeed()), mass(body.getMass()){}

phys::Body phys::Body::operator=(phys::Body body) {
    return phys::Body(body);
}

const phys::Vector phys::Body::updateSpeed(phys::Vector dv) {
    phys::Vector t = speed;
    speed = speed + dv;
    return t;
}
