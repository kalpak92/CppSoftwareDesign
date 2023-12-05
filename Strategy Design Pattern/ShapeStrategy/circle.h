#include "shape.h"
#include "draw_strategy.h"
#include <memory>

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
    using DrawCircleStrategy = DrawStrategy<Circle>;

    /**
     * @brief Constructor for Circle class.
     * 
     * @param radius The radius of the circle.
     * @param drawer A unique pointer to the DrawCircleStrategy object used for drawing the circle.
     *               Configration of the drawer is done externally via dependency injection.
     */
    explicit Circle(double radius, std::unique_ptr<DrawCircleStrategy> drawer)
        : radius_(radius),
          drawer_(std::move(drawer))
    {

    }

    /**
     * @brief Draws the circle.
     * 
     * This function is responsible for drawing the circle on the screen.
     * It takes some arguments (not specified here) and returns nothing.
     * The function is marked as const and is overridden from the base class.
     */
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