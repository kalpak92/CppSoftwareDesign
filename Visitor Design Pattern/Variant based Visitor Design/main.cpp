#include "circle.h"
#include "square.h"
#include "shape.h"
#include "draw_all_shapes.h"
#include <cstdlib>

int main()
{
   Shapes shapes;

   shapes.emplace_back(Circle{ 2.3 });
   shapes.emplace_back(Square{ 1.2 });
   shapes.emplace_back(Circle{ 4.1 });

   draw_all_shapes(shapes);

   return EXIT_SUCCESS;
}