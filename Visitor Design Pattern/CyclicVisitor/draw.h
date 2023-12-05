#include "circle.h"
#include "shape_visitor.h"
#include "square.h"
#include <iostream>

#ifndef DRAW_H
#define DRAW_H

class Draw : public ShapeVisitor
{
public:
    void visit(const Circle& circle) const override
    {
        std::cout << "Drawing a circle with radius " << circle.radius() << std::endl;
    }

    void visit(const Square& square) const override
    {
        std::cout << "Drawing a square with side " << square.side() << std::endl;
    }
};

#endif