#include "abstract_visitor.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual ~Shape() = default;

    virtual void accept(AbstractVisitor const&) = 0;
};

#endif // SHAPE_H