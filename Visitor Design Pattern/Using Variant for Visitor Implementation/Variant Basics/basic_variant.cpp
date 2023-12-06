#include <cstdlib>
#include <iostream>
#include <string>
#include <variant>

struct Print
{
    void operator()(int value) const
    {
        std::cout << "int: " << value << "\n";
    }

    void operator()(double value) const
    {
        std::cout << "double: " << value << "\n";
    }

    void operator()(std::string const& value) const
    {
        std::cout << "string: " << value << "\n";
    }
};

int main()
{
    std::variant<int, double, std::string> v{};

    v = 42;        // Assigns the 'int' 42 to the variant  2
    v = 3.14;      // Assigns the 'double' 3.14 to the variant  3
    v = 2.71F;     // Assigns a 'float', which is promoted to 'double'  4
    v = "Bjarne";  // Assigns the string literal 'Bjarne' to the variant  5
    v = 43;        // Assigns the 'int' 43 to the variant  6

    int const i = std::get<int>(v);  // Direct access to the value  7

    int* const pi = std::get_if<int>(&v);  // Direct access to the value  8

    std::visit(Print{}, v);

    return EXIT_SUCCESS;
}