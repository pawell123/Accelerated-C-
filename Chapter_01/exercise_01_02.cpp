// Exercise 1.2
// Are the following definitions valid? Why or why not?

#include <iostream>
#include <string>

int main()
{
    const std::string exclam = "!";
    const std::string message = "Hello" + ", world" + exclam;

    std::cout << message << std::endl;

    return 0;
}

// The first definition is valid.
// The second definition is NOT valid. There are no operator+ for string literals.
