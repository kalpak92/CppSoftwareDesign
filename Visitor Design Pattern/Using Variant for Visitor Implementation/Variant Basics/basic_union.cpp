#include <iostream>
#include <string>
#include <vector>

union S
{
    std::string str;
    std::vector<int> vec;

    ~S() {}
};

int main()
{
    S s = {"Hello, world"};

    // At this point, reading from s.vec is undefined behavior
    std::cout << "s.str = " << s.str << '\n';

    // Call destructor of the contained objects
    s.str.~basic_string<char>();

    // And a Constructor!
    new (&s.vec) std::vector<int>;

    // Now, s.vec is the active member of the union
    s.vec.push_back(10);
    std::cout << s.vec.size() << '\n';

    // Destruct again
    s.vec.~vector<int>();

}