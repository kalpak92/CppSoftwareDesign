#ifndef DRAW_STRATEGY_H
#define DRAW_STRATEGY_H

/**
 * @brief Interface for draw strategies.
 * 
 * The draw strategy is responsible for drawing the shape on the screen.
 * This is a pure virtual class. A concrete class must be derived from this
 * class to implement the draw function.
 * 
 * @tparam T The type of the object to draw.
 * 
 * @see DrawSquareStrategy
 * @see DrawCircleStrategy
 */
template<typename T>
class DrawStrategy
{
public:
    virtual ~DrawStrategy() = default;
    virtual void draw(T const&) const = 0;
};

#endif // DRAW_STRATEGY_H