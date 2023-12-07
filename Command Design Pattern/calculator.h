#include "calculator_command.h"
#include <stack>
#include <memory>

class Calculator
{
    public:
        void compute(std::unique_ptr<CalculatorCommand> command);
        
        void undoLast();

        int result() const;
        void clear();
    
    private:
        using CommandStack = std::stack<std::unique_ptr<CalculatorCommand>>;    // Note the Dependency Inversion Principle here

        int current_{};
        CommandStack command_stack_;
};