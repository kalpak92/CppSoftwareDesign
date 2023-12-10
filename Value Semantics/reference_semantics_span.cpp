#include <cstdlib>
#include <iostream>
#include <span>
#include <vector>


void print(std::span<int> s)
{
    std::cout << " (";
    for(int i : s)
    {
        std::cout << i << " ";
    }

    std::cout << ")\n";
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    std::vector<int> const w{v};
    /**
     * The std::span is a lightweight, non-owning reference to a contiguous sequence, or a range of objects.
    */
    std::span<int> const s{v};

    //  w[2] = 99; // FAILS. w is const.
    s[2] = 99;

    print(s);

    v = { 5, 6, 7, 8, 9 };  
    s[2] = 99;  // Works!

    // Prints ?
    print( s );

    /**
     * On line 33, you're changing the vector v to a new sequence of numbers.
     * On line 34, you're trying to modify the std::span s again.
     * 
     * The problem is that s was initialized with the original data of v. 
     * When you change v, s doesn't automatically update to reference the new data. 
     * So, when you try to modify s on line 34, you're actually modifying the old data of v, 
     * which no longer exists. 
     * This is undefined behavior.
     * 
     * To fix this, you should create a new std::span 
     * whenever you change the data that the std::span is supposed to reference:
     * 
     * v = { 5, 6, 7, 8, 9 };
     * std::span<int> s_new{v};
     * s_new[2] = 99;  // Works!
     * Now, s_new correctly references the new data of v, and the code behaves as expected.
    */
}