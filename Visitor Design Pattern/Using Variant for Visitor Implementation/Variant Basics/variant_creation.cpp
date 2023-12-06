#include <variant>
#include <vector>
#include <iostream>

class NotSimple
{
    public:
        NotSimple(int, float) { }
};

int main()
{
    // default initialization
    std::variant<int, float> intFloat;
    std::cout << intFloat.index() << std::endl;

    /**
     * The line of code you've highlighted is a declaration of a std::variant variable named okInit. 
     * std::variant is a class template available in C++17 and later that represents a type-safe union. 
     * It can hold an instance of any of the types you specify.
     * 
     * In this case, okInit can hold an instance of either std::monostate, NotSimple, or int.
     * 
     * std::monostate is a standard library type that serves as a placeholder. 
     * It's typically used when you want to have a std::variant that can represent an "empty" or "uninitialized" state. 
     * This is useful because std::variant requires that it always holds a value of one of its alternative types.
     * 
     * When you declare a std::variant without providing an initial value, it will default-construct a value of its first alternative type. 
     * In this case, because std::monostate is the first type listed, okInit will be initialized with a std::monostate value.
    */
    std::variant<std::monostate, NotSimple, int> okInit;
    std::cout << okInit.index() << std::endl;

    // Pass a value
    std::variant<int, float, std::string> intFloatString {10.5f};
    std::cout << intFloatString.index() << ", value: " << std::get<float>(intFloatString) << std::endl;

    // Use of in_place_index to resolve ambiguity
    std::variant<long, float, std::string> longFloatString { std::in_place_index<1>, 7.6 };
    std::cout << longFloatString.index() << ", value: " << std::get<float>(longFloatString) << std::endl;

    // in_place_index for complex types
    std::variant<std::vector<int>, std::string> vecStr { std::in_place_index<0>, { 0, 1, 2, 3 }};
    std::cout << vecStr.index() << ", vector size: " << std::get<std::vector<int>>(vecStr).size() << std::endl;

    // copy-initialize from other variant
    std::variant<int, float> intFloatSecond { intFloat };
    std::cout << intFloatSecond.index() << ", value " << std::get<int>(intFloatSecond) << std::endl;
}