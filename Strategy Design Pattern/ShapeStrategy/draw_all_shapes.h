#include <vector>
#include <memory>

class Shape;

void drawAllShapes(std::vector<std::unique_ptr<Shape>> const& shapes);