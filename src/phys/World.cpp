#include "World.h"

World::World(double dt) : dt(dt) {}

World::~World() { objects.clear(); }

void World::tick() {

    phys::Vector phi[objects.size()];

    for (int i = 0; i < objects.size(); ++i) {

        phys::Body b = objects[i].getBody();
        const phys::Vector vec = phys::Vector(objects[i].getCoord());

        for (int j = 0; j < objects.size(); ++j) {

            if (j == i)
                continue;

            phys::Vector v = vec - phys::Vector(objects[j].getCoord());
            double l = v.length();
            v.normalize();

            //F=ma, F=GmM/R^2 => a=GM/R^2
            v = v * (GRAV_CONST * b.getMass()/SQR(l));

            phi[j] = phi[j] + v;
        }
    }

    for (int i = 0; i < objects.size(); ++i) {
        phys::Body b = objects[i].getBody();
        phys::Vector vector = b.updateSpeed(dt) * dt;
        objects[i].move(vector);
        b.increaseAcceleration(phi[i]);
    }
}

void World::addBody(phys::Body body, Coordinate coord) {
    addBody(World::Object(body, coord));
}

void World::addBody(World::Object obj) {
    objects.push_back(obj);
}

void World::Object::move(phys::Vector vector) {
    move(vector.getEnd().getX(),
         vector.getEnd().getY(),
         vector.getEnd().getZ());
}

void World::Object::move(double dx, double dy, double dz) {
    coord.move(dx, dy, dz);
}

World::Object::Object(phys::Body b, const Coordinate &c) :
        body(b), coord(c) {}

double World::Object::getDistance(World::Object object) const {
    return coord.getDistance(object.coord);
}
