#ifndef SPACESIM_CORDS_H
#define SPACESIM_CORDS_H


class Coordinate {
private:
    double x;
    double y;

public:

    Coordinate();

    Coordinate(double, double);

    Coordinate(Coordinate, double, double);

    inline double getX() const { return x; }

    inline double getY() const { return y; }

    inline double getDistance(Coordinate) const;

    void move(double, double);

};


inline static double distance(double, double, double, double);

#endif //SPACESIM_CORDS_H
