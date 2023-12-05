#include "draw_all_shapes.h"
#include "shape.h"

void drawAllShapes(std::vector<std::unique_ptr<Shape>> const& shapes)
{
    for (auto const& shape : shapes)
    {
        shape->draw();
    }
}