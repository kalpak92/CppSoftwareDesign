#include "draw_all_shapes.h"
#include "draw.h"

void draw_all_shapes(const Shapes& shapes)
{
    for (const auto& shape : shapes)
    {
        std::visit(Draw{}, shape);
    }
}