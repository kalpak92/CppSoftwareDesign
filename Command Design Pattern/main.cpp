#include "calculator.h"
#include "add.h"
#include "subtract.h"
#include <cstdlib>
#include <iostream>

int main()
{
    Calculator calculator{};

    auto op1 = std::make_unique<Add>(5);
    auto op2 = std::make_unique<Subtract>(3);
    auto op3 = std::make_unique<Add>(10);
    auto op4 = std::make_unique<Subtract>(2);

    calculator.compute(std::move(op1));
    calculator.compute(std::move(op2));
    calculator.compute(std::move(op3));
    calculator.compute(std::move(op4));

    calculator.undoLast();

    int const result = calculator.result();

    std::cout << "Result: " << result << std::endl;

    return EXIT_SUCCESS;
}