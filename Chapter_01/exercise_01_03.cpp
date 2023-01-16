// Exercise 1.3
// Is the following program valid? If so, what does it do? If not, why not?

#include <iostream>
#include <string>

int main()
{
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    }
    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }

    return 0;
}

// The code is valid.
// Output:
// a string
// another string
