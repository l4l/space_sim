#ifndef SPACESIM_CORDS_H
#define SPACESIM_CORDS_H

#define SQR(a) ((a)*(a))

class Coordinate {

public:
    Coordinate();
    Coordinate(const Coordinate&);
    Coordinate(double, double, double);

    void move(double, double, double);

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    double getDistance() const;
    double getDistance(Coordinate) const;

private:
    double x;
    double y;
    double z;
};


inline static double distance(double, double, double,
                              double, double, double);

#endif //SPACESIM_CORDS_H
