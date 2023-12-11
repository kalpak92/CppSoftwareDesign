
#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
    public:
        virtual ~Shape() = default;
        virtual void draw() const = 0;
};

#endif // SHAPE_H