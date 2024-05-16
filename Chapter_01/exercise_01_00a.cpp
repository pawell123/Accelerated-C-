// Exercise 1.0a
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";

    std::string name;
    std::cin >> name;

    std::cout << "Welcome " << name << '!' << std::endl;

    return 0;
}
