// Exercise 1.1
// Are the following definitions valid? Why or why not?

#include <iostream>
#include <string>

int main()
{
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";

    std::cout << message << std::endl;

    return 0;
}

// The code is valid (operator+ is left-associative)
