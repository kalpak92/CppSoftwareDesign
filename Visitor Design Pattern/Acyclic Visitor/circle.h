#include "shape.h"
#include "visitor.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
    explicit Circle(double radius) : radius_(radius) {}

    void accept(AbstractVisitor const& visitor) override
    {
        if (auto const* v = dynamic_cast<Visitor<Circle> const*>(&visitor))
        {
            v->visit(*this);
        }
    }

    double radius() const { return radius_; }

private:
    double radius_;
};

#endif // CIRCLE_H