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

    const std::string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');
    const std::string third = "* " + greeting + " *";

    std::cout << first << std::endl
              << second << std::endl
              << third << std::endl
              << second << std::endl
              << first << std::endl;

    return 0;
}
