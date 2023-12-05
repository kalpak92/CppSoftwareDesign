#include "circle.h"
#include "square.h"
#include "draw_all_shapes.h"
#include "openGL_circle_strategy.h"
#include "openGL_square_strategy.h"
#include <memory>
#include <vector>
#include <cstdlib>

int main()
{
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes{};

    shapes.emplace_back(
        std::make_unique<Circle>(
            2.3,
            std::make_unique<OpenGLCircleStrategy>()
        )
    );

    shapes.emplace_back(
        std::make_unique<Square>(
            3.4,
            std::make_unique<OpenGLSquareStrategy>()
        )
    );

    shapes.emplace_back(
        std::make_unique<Circle>(
            4.5,
            std::make_unique<OpenGLCircleStrategy>()
        )
    );

    drawAllShapes(shapes);

    return EXIT_SUCCESS;
}