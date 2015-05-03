#ifndef SPACESIM_CORDS_H
#define SPACESIM_CORDS_H

#define SQR(a) ((a)*(a))

class Coordinate {
private:
    double x;
    double y;
    double z;

public:

    Coordinate();

    Coordinate(const Coordinate&);

    Coordinate(double, double, double);

    void move(double, double, double);

    void invert();

    inline double getX() const { return x; }

    inline double getY() const { return y; }

    inline double getZ() const { return z; }

    inline double getDistance() const;

    inline double getDistance(Coordinate) const;

};


inline static double distance(double, double, double,
                              double, double, double);

#endif //SPACESIM_CORDS_H
