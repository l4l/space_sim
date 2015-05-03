#ifndef SPACESIM_WORLD_H
#define SPACESIM_WORLD_H

#include "Body.h"
#include "vector"

#define GRAV_CONST 6.6719e-11

class World {
private:
    class Object {
    private:
        phys::Body body;
        Coordinate coord;

        Object(phys::Body b, const Coordinate &c);

        double getDistance(Object) const;

    public:

        const phys::Body getBody() const {
            return body;
        }

        const Coordinate getCoord() const {
            return coord;
        }

        void move(phys::Vector);

        void move(double, double, double);
    };

    std::vector<Object> objects;

    double dt;
public:
    World(double);
    ~World();

    void tick();
};


#endif //SPACESIM_WORLD_H
