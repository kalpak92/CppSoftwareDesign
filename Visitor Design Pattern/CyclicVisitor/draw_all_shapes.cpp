#include "draw_all_shapes.h"
#include "draw.h"
#include "shape.h"

/**
 * Draws all the shapes in the given vector using the Draw visitor.
 * 
 * @param shapes The vector of shapes to be drawn.
 */
void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes)
{
    Draw draw;
    for (const auto& shape : shapes)
    {
        shape->accept(draw);
    }
}