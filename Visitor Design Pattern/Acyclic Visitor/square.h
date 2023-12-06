#include "shape.h"
#include "visitor.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape
{
public:
    explicit Square(double side) : side_(side) {}

    void accept(AbstractVisitor const& visitor) override
    {
        if (auto const* v = dynamic_cast<Visitor<Square> const*>(&visitor))
        {
            v->visit(*this);
        }
    }

    double side() const { return side_; }
private:
    double side_;
};

#endif // SQUARE_H