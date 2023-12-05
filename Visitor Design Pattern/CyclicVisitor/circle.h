#include "shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
    explicit Circle(double radius) : radius_(radius) {}

    void accept(const ShapeVisitor& visitor) override
    {
        visitor.visit(*this);
    }

    double radius() const { return radius_; }

private:
    double radius_;
};

#endif