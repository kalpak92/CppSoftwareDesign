#include "circle.h"
#include "square.h"
#include "draw_all_shapes.h"
#include <cstdlib>
#include <memory>
#include <vector>

int main()
{
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes{};

    shapes.emplace_back(std::make_unique<Circle>(1.0));
    shapes.emplace_back(std::make_unique<Square>(2.0));
    shapes.emplace_back(std::make_unique<Circle>(3.0));

    draw_all_shapes(shapes);

    return EXIT_SUCCESS;
}