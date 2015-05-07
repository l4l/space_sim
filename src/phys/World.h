#ifndef SPACESIM_WORLD_H
#define SPACESIM_WORLD_H

#include "Body.h"
#include "vector"

#define GRAV_CONST 6.6719e-11

class World {
public:
    class Object;

    World(double);
    ~World();

    void tick();

    void addBody(const World::Object);
    void addBody(const phys::Body, const Coordinate);

    void removeBody(int);
    void removeBody(std::string);

    const std::vector<Object> &getObjects() const {
        return objects;
    }

    double getDt() const {
        return dt;
    }

private:
    std::vector<Object> objects;
    double dt;

public:
    class Object {

    public:
        Object() {}
        Object(phys::Body b, const Coordinate &c);

        double getDistance(Object) const;

        void move(phys::Vector);
        void move(double, double, double);

        const phys::Body getBody() const {
            return body;
        }

        const Coordinate getCoord() const {
            return coord;
        }

    private:
        phys::Body body;
        Coordinate coord;
    };
};


#endif //SPACESIM_WORLD_H
