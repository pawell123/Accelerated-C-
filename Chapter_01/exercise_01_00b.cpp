// Exercise 1.0b
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";

    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";
    const std::string spaces(greeting.size(), ' ');

    const std::string secondLine = "* " + spaces + " *";
    const std::string firstLine(secondLine.size(), '*');
    const std::string thirdLine = "* " + greeting + " *";

    std::cout << firstLine << std::endl
              << secondLine << std::endl
              << thirdLine << std::endl
              << secondLine << std::endl
              << firstLine << std::endl;

    return 0;
}
