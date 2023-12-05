class Circle;
class Square;

#ifndef SHAPES_VISITOR
#define SHAPES_VISITOR
/**
 * @brief The ShapeVisitor class is an abstract base class for visitors that can visit different shapes.
 * 
 * This class defines the interface for visiting different shapes, such as circles and squares.
 * Subclasses of ShapeVisitor can implement the visit() method to perform specific operations on each shape.
 */
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor() = default;

    /**
     * @brief Visit a circle shape.
     * 
     * This method is called when the visitor visits a circle shape.
     * Declaring it as const ensures that the function does not modify the state of the ShapeVisitor object it's called on. 
     * This is important in scenarios where you want to guarantee that the visitor's visit operation is a read-only operation 
     * that doesn't alter the visitor itself.
     * 
     * @param circle The circle shape to visit.
     */
    virtual void visit(const Circle& circle) const = 0;

    /**
     * @brief Visit a square shape.
     * 
     * This method is called when the visitor visits a square shape.
     * Declaring it as const ensures that the function does not modify the state of the ShapeVisitor object it's called on. 
     * This is important in scenarios where you want to guarantee that the visitor's visit operation is a read-only operation 
     * that doesn't alter the visitor itself.
     * 
     * @param square The square shape to visit.
     */
    virtual void visit(const Square& square) const = 0;
};
#endif