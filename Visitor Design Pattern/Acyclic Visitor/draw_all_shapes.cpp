#include "draw_all_shapes.h"
#include "draw.h"
#include "shape.h"

void draw_all_shapes(std::vector<std::unique_ptr<Shape>> const& shapes)
{
    for (auto const& shape : shapes)
    {
        shape->accept(Draw{});
    }
}