#include "abstract_visitor.h"
#include "visitor.h"
#include "circle.h"
#include "square.h"
#include <iostream>

#ifndef DRAW_H
#define DRAW_H

class Draw : public AbstractVisitor,
             public Visitor<Circle>,
             public Visitor<Square>
{
public:
    void visit(Circle const& circle) const override
    {
        std::cout << "Draw a circle with radius " << circle.radius() << std::endl;
    }

    void visit(Square const& square) const override
    {
        std::cout << "Draw a square with side " << square.side() << std::endl;
    }
};

#endif // DRAW_H