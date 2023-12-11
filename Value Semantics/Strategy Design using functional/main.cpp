#include "circle.h"
#include "square.h"
#include "openGL_circle_strategy.h"
#include "openGL_square_strategy.h"
#include <vector>
#include <memory>
#include <cstdlib>

int main()
{
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes{};

    // The Circle object is being constructed with two arguments: 1.0 and OpenGLCircleStrategy{}.
    shapes.emplace_back(std::make_unique<Circle>(1.0, OpenGLCircleStrategy{}));
    shapes.emplace_back(std::make_unique<Square>(1.0, OpenGLSquareStrategy{}));
    shapes.emplace_back(std::make_unique<Circle>(2.0, OpenGLCircleStrategy{}));

    for (auto const& shape : shapes)
    {
        shape->draw();
    }
    
    return EXIT_SUCCESS;
}