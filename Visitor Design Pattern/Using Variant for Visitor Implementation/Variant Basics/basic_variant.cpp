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

struct SampleVisitor
{
    void operator()(int i) const { 
        std::cout << "int: " << i << "\n"; 
    }
    void operator()(float f) const { 
        std::cout << "float: " << f << "\n"; 
    }
    void operator()(const std::string& s) const { 
        std::cout << "string: " << s << "\n"; 
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


    std::variant<int, float, std::string> intFloatString;
    static_assert(std::variant_size_v<decltype(intFloatString)> == 3);

    // default initialized to the first alternative, should be 0
    std::visit(SampleVisitor{}, intFloatString);

    // index will show the currently used 'type'
    std::cout << "index = " << intFloatString.index() << std::endl;
    intFloatString = 100.0f;
    std::cout << "index = " << intFloatString.index() << std::endl;
    intFloatString = "hello super world";
    std::cout << "index = " << intFloatString.index() << std::endl;

    // try with get_if:
    if (const auto intPtr (std::get_if<int>(&intFloatString)); intPtr) 
        std::cout << "int!" << *intPtr << "\n";
    else if (const auto floatPtr (std::get_if<float>(&intFloatString)); floatPtr) 
        std::cout << "float!" << *floatPtr << "\n";

    if (std::holds_alternative<int>(intFloatString))
        std::cout << "the variant holds an int!\n";
    else if (std::holds_alternative<float>(intFloatString))
        std::cout << "the variant holds a float\n";
    else if (std::holds_alternative<std::string>(intFloatString))
        std::cout << "the variant holds a string\n";  

    // try/catch and bad_variant_access
    try 
    {
        auto f = std::get<float>(intFloatString); 
        std::cout << "float! " << f << "\n";
    }
    catch (std::bad_variant_access&) 
    {
        std::cout << "our variant doesn't hold float at this moment...\n";
    }

    // visit:
    std::visit(SampleVisitor{}, intFloatString);
    intFloatString = 10;
    std::visit(SampleVisitor{}, intFloatString);
    intFloatString = 10.0f;
    std::visit(SampleVisitor{}, intFloatString);

    return EXIT_SUCCESS;
}