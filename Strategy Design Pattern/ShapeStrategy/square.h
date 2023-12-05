#include "shape.h"
#include "draw_strategy.h"
#include <memory>

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape
{
public:
    using DrawSquareStrategy = DrawStrategy<Square>;

    explicit Square(double side, std::unique_ptr<DrawSquareStrategy> drawer)
        : side_(side),
          drawer_(std::move(drawer))
    {

    }

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