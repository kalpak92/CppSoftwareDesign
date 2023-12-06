#include <iostream>
#include <variant>

class MyType
{
public:
    MyType()
    {
        std::cout << "MyType default constructor" << std::endl;
    }

    ~MyType()
    {
        std::cout << "MyType destructor" << std::endl;
    }
};

class OtherType
{
public:
    OtherType()
    {
        std::cout << "OtherType default constructor" << std::endl;
    }

    OtherType(const OtherType&)
    {
        std::cout << "OtherType copy constructor" << std::endl;
    }

    ~OtherType()
    {
        std::cout << "OtherType destructor" << std::endl;
    }
};

int main()
{
    std::variant<MyType, OtherType> v;
    v = OtherType();

    return 0;
}