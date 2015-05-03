#ifndef SPACESIM_CORDS_H
#define SPACESIM_CORDS_H

#define SQR(a) ((a)*(a))
#define ABS(x) (x >= 0 ? x: -x)
#define MIN(x, y) (x >= y ? y: x)

class Coordinate {
private:
    double x;
    double y;

public:

    Coordinate();

    Coordinate(const Coordinate&);

    Coordinate(double, double);

    Coordinate(Coordinate, double, double);

    void move(double, double);

    void invert();

    inline double getX() const { return x; }

    inline double getY() const { return y; }

    inline double getDistance() const;

    inline double getDistance(Coordinate) const;

};


inline static double distance(double, double, double, double);

#endif //SPACESIM_CORDS_H
