#include "shape.h"
#include "draw_strategy.h"
#include <memory>

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape
{
public:
    using DrawSquareStrategy = DrawStrategy<Square>;

    /**
     * @brief Constructor for Square class.
     * 
     * @param side The side of the square.
     * @param drawer A unique pointer to the DrawSquareStrategy object used for drawing the square.
     *               Configration of the drawer is done externally via dependency injection. 
     */
    explicit Square(double side, std::unique_ptr<DrawSquareStrategy> drawer)
        : side_(side),
          drawer_(std::move(drawer))
    {

    }

    /**
     * @brief Draws the square.
     * 
     * This function is responsible for drawing the square on the screen.
     * It takes some arguments (not specified here) and returns nothing.
     * The function is marked as const, indicating that it does not modify the object's state.
     * The function overrides a virtual function from the base class.
     */
    void draw(/*some arguments*/) const override
    {
        drawer_->draw(*this);
    }

    ~Square() {}

private:
    /* data */
    double side_;
    std::unique_ptr<DrawSquareStrategy> drawer_;
};

#endif // SQUARE_H