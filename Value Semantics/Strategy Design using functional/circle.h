#include "shape.h"
#include <functional>
#include <utility>

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
    public:
        using DrawStrategy = std::function<void(Circle const&)>;

        explicit Circle(double radius, DrawStrategy drawStrategy)
            : radius_{radius}
            , drawStrategy_{std::move(drawStrategy)}
        {}

        void draw() const override
        {
            drawStrategy_(*this);
        }

        double radius() const
        {
            return radius_;
        }
    
    private:
        double radius_;
        DrawStrategy drawStrategy_;
};

#endif // CIRCLE_H