#include "circle.h"
#include "draw_strategy.h"
#include <iostream>

class OpenGLCircleStrategy : public DrawStrategy<Circle>
{
public:
    explicit OpenGLCircleStrategy(/* Drawing related arguments */)
    {}

    void draw(Circle const& circle) const override
    {
        std::cout << "Drawing a circle by means of OpenGL" << std::endl;
    }

private:
};