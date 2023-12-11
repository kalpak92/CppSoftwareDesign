#include "shape.h"
#include <functional>

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape
{
    public:
        using DrawStrategy = std::function<void(Square const&)>;

        explicit Square(double side, DrawStrategy drawStrategy)
            : side_{side}
            , drawStrategy_{std::move(drawStrategy)}
        {}

        void draw() const override
        {
            drawStrategy_(*this);
        }

        double side() const
        {
            return side_;
        }
    
    private:
        double side_;
        DrawStrategy drawStrategy_;
};

#endif // SQUARE_H