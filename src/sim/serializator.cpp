#include "serializator.h"

#include "iostream"

std::ostream &operator<<(std::ostream &out, const Coordinate &coordinate) {
    return out<<coordinate.getX()<<coordinate.getY()<<coordinate.getZ();
}

std::istream &operator>>(std::istream &in, Coordinate &coordinate) {
    double x, y, z;
    in>>x>>y>>z;
    coordinate = Coordinate(x, y, z);
    return in;
}

std::ostream &operator<<(std::ostream &out, phys::Vector &vector) {
    Coordinate coord(vector.getEnd());
    return out<<&coord;
}

std::istream &operator>>(std::istream &in, phys::Vector &vector) {
    Coordinate coord;
    in>>coord;
    vector = phys::Vector(coord);
    return in;
}

std::ostream &operator<<(std::ostream &out, phys::Body &body) {
    return out<<body.getName()<<body.getMass()<<&body.getSpeed();
}

std::istream &operator>>(std::istream &in, phys::Body &body) {
    std::string name;
    double mass;
    phys::Vector speed, acc;
    in>>name>>mass>>speed>>acc;
    body = phys::Body(name, speed, mass);
    return in;
}

std::ostream &operator<<(std::ostream &out, World::Object &object) {
    phys::Body body(object.getBody());
    Coordinate coord(object.getCoord());
    return out<<body<<&coord;
}

std::istream &operator>>(std::istream &in, World::Object &object) {
    phys::Body *body;
    Coordinate coord;
    in>>*body>>coord;
    object = World::Object(*body, coord);
    return in;
}

std::ostream &operator<<(std::ostream &out, World &world) {
    out<<world.getDt();
    out<<world.getObjects().size();
    const std::vector<World::Object> objects = world.getObjects();
    for (auto i = 0; i < objects.size(); ++i)
        out<<&objects[i];
    return out;
}

std::istream &operator>>(std::istream &in, World &world) {
    double dt;
    ulong size;
    World::Object *object;
    in>>dt>>size;

    world = World(dt);
    for (int i = 0; i < size; ++i) {
        in>>*object;
        world.addBody(*object);
    }
    return in;
}
