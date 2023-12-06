#include <variant>
#include <string>
#include <iostream>

auto PrintVisitor = [](const auto& t)
{
    std::cout << t << std::endl;
};

auto TwiceMoreVisitor = [](auto& t) 
{ 
    t*= 2; 
};

struct MultiplyVisitor
{
    float mFactor;

    MultiplyVisitor(float factor) : mFactor(factor) { }

    void operator()(int& i) const 
    {
        i *= static_cast<int>(mFactor);
    }

    void operator()(float& f) const 
    {
        f *= mFactor;
    }

    void operator()(std::string& ) const 
    {
        // nothing to do here...
    }
};

int main()
{
    std::variant<int, float, std::string> intFloatString {"Hello world!"};
    std::visit(PrintVisitor, intFloatString);

    std::variant<int, float> intFloat { 20.4f };
    std::visit(PrintVisitor, intFloat);

    std::visit(TwiceMoreVisitor, intFloat);
    std::visit(PrintVisitor, intFloat);

    std::visit(MultiplyVisitor(0.5f), intFloat);
    std::visit(PrintVisitor, intFloat);  
}