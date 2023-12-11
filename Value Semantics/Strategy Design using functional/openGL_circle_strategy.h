#include "circle.h"
#include <iostream>

class OpenGLCircleStrategy
{
    public:
        explicit OpenGLCircleStrategy() {};

        void operator()(Circle const& circle) const
        {
            std::cout << "Drawing a circle with OpenGLCircleStrategy: " << circle.radius() << "\n";
        }

    private:
        // OpenGL specific data
};