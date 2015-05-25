#include <iostream>
#include "World.h"

World::World(double dt) : dt(dt) {}
World::~World() { objects.clear(); }

void World::tick() {

    phys::Vector acc[objects.size()];

    for (int i = 0; i < objects.size(); ++i) {
        phys::Body b = objects[i].getBody();
        const phys::Vector vec = phys::Vector(objects[i].getCoord());

        for (int j = 0; j < objects.size(); ++j) {
            if (j == i)
                continue;

            phys::Vector v = vec - phys::Vector(objects[j].getCoord());
            double l = v.length();
            v.normalize();


            v = v * (GRAV_CONST * b.getMass()/SQR(l));

            acc[j] = acc[j] + v;
        }
    }

    for (int i = 0; i < objects.size(); ++i) {
        phys::Body b = objects[i].getBody();
        phys::Vector ds = (objects[i].updateSpeed(acc[i]*dt) + b.getSpeed())/2 * dt;
        objects[i].move(ds);
    }
}

void World::addBody(phys::Body body, Coordinate coord) {
    addBody(World::Object(body, coord));
}

void World::addBody(World::Object obj) {
    objects.push_back(obj);
}

void World::removeBody(int id) {
    objects.erase(objects.begin() + id);
}

void World::removeBody(std::string name) {
    for (auto i = objects.begin(); i != objects.end(); ++i)
        if (i->getBody().getName() == name)
            objects.erase(i);

}

World::Object::Object(phys::Body b, const Coordinate &c) :
        body(b), coord(c) {}

void World::Object::move(phys::Vector ds) {
    move(ds.getEnd().getX(),
         ds.getEnd().getY(),
         ds.getEnd().getZ());
}

void World::Object::move(double dx, double dy, double dz) {
    coord.move(dx, dy, dz);
}

double World::Object::getDistance(World::Object object) const {
    return coord.getDistance(object.coord);
}

const phys::Vector World::Object::updateSpeed(phys::Vector v){
    return  body.updateSpeed(v);
}