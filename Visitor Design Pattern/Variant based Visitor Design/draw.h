#include "shape.h"
#include <iostream>

#ifndef DRAW_H
#define DRAW_H

class Draw
{
public:
    void operator()(const Circle& circle) const
    {
        std::cout << "Drawing a circle of radius " << circle.radius() << std::endl;
    }

    void operator()(const Square& square) const
    {
        std::cout << "Drawing a square of side " << square.side() << std::endl;
    }
};

#endif // DRAW_H