#include <vector>
#include <cassert>

int main()
{
    std::vector<int> v1{ 1, 2, 3, 4, 5 };

    auto v2{ v1 };

    assert( v1 == v2 );

    /**
     * this line is ensuring that the vectors v1 and v2 each have their own separate data, 
     * which is a fundamental principle of value semantics in C++.
     * 
     * The data pointers of two vectors, v1 and v2, are not the same.
     * 
     * The data() function is a member function of the std::vector class in C++. 
     * It returns a pointer to the first element in the vector. 
     * If the vector is empty, the returned pointer value shall not be dereferenced.
    */
    assert( v1.data() != v2.data() );

    v2[2] = 99;

    assert( v1 != v2 );

    auto const v3{ v1 };

    // v3[2] = 99;  // Compilation error!
}