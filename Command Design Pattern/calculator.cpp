#include "calculator.h"

void Calculator::compute(std::unique_ptr<CalculatorCommand> command)
{
    current_ = command->execute(current_);
    command_stack_.push(std::move(command));
}

void Calculator::undoLast()
{
    if (command_stack_.empty())
    {
        return;
    }

    auto command = std::move(command_stack_.top());
    command_stack_.pop();

    current_ = command->undo(current_);
}

int Calculator::result() const
{
    return current_;
}

void Calculator::clear()
{
    current_ = 0;

    /**
     * CommandStack{} creates a temporary, empty CommandStack object. 
     * The swap function then exchanges the contents of command_stack_ with this temporary object. 
     * Since the temporary object is empty, the effect is to clear command_stack_.
     * 
     * The advantage of this approach over calling command_stack_.clear() is that 
     * it also reduces the capacity of command_stack_ to zero, freeing up memory. 
     * After this line of code, command_stack_ is guaranteed to not be holding onto any allocated memory
    */
    CommandStack{}.swap(command_stack_);
}