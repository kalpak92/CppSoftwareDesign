#include "point.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    explicit Square(double side) : side_(side) { }

    int side() const { return side_; }

    Point center() const { return center_; }

private:
    double side_;
    Point center_;
};

#endif // SQUARE_H