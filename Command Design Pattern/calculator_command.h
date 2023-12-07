#ifndef CALCULATOR_COMMAND_H
#define CALCULATOR_COMMAND_H

class CalculatorCommand
{
    public:
        virtual ~CalculatorCommand() {}

        virtual int execute(int i) const = 0;
        virtual int undo(int i) const = 0;
};

#endif // CALCULATOR_COMMAND_H