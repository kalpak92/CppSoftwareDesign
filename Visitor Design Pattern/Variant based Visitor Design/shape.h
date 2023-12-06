#include <variant>
#include "circle.h"
#include "square.h"

using Shape = std::variant<Circle, Square>;