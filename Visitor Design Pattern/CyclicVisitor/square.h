#include "shape.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape
{
public:
    explicit Square(double side) : side_(side) {}

    void accept(const ShapeVisitor& visitor) override
    {
        visitor.visit(*this);
    }

    double side() const { return side_; }

private:    
    double side_;
};

#endif