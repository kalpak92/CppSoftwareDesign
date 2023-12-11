#include "square.h"
#include <iostream>

class OpenGLSquareStrategy
{
    public:
        explicit OpenGLSquareStrategy() {};

        void operator()(Square const& square) const
        {
            std::cout << "Drawing a square with OpenGLSquareStrategy: " << square.side() << "\n";
        }

    private:
        // OpenGL specific data
};