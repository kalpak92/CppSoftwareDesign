#include "shape.h"
#include "draw_strategy.h"
#include <memory>

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
    using DrawCircleStrategy = DrawStrategy<Circle>;

    explicit Circle(double radius, std::unique_ptr<DrawCircleStrategy> drawer)
        : radius_(radius),
          drawer_(std::move(drawer))
    {

    }

    void draw(/*some arguments*/) const override
    {
        drawer_->draw(*this);
    }

    ~Circle() {}

private:
    /* data */
    double radius_;
    std::unique_ptr<DrawCircleStrategy> drawer_;
};

#endif // CIRCLE_H