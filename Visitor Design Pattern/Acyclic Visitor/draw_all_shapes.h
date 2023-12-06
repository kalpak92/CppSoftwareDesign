#include <memory>
#include <vector>

class Shape;

void draw_all_shapes(std::vector<std::unique_ptr<Shape>> const& shapes);