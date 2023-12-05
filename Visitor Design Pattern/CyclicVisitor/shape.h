#include "shape_visitor.h"

#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
public:
     ~Shape() = default;

    /**
     * @brief Accept a visitor.
     * 
     * This method is called when a visitor visits a shape.
     * 
     * @param visitor The visitor to accept.
     */
    virtual void accept(const ShapeVisitor& visitor) = 0;
};
#endif