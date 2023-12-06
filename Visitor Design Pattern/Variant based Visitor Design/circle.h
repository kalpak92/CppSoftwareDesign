#include "point.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    explicit Circle(double radius) 
        : radius_(radius) { }

    double radius() const { return radius_; }

    Point center() const { return center_; }

private:
    double radius_;
    Point center_;
};

#endif // CIRCLE_H