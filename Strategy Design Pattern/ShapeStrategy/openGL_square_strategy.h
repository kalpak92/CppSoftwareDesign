#include "square.h"
#include "draw_strategy.h"
#include <iostream>

class OpenGLSquareStrategy : public DrawStrategy<Square>
{
public:
    explicit OpenGLSquareStrategy(/* Drawing related arguments */)
    {}

    void draw(Square const& square) const override
    {
        std::cout << "Drawing a square by means of OpenGL" << std::endl;
    }

private:
};