// Exercise 2.9
// Write a program that asks the user to enter two numbers and tells the user which number is larger than the other.

#include <iostream>

int main()
{
    std::cout << "Enter two numbers: ";

    int first;
    int second;
    std::cin >> first >> second;

    if (first > second)
    {
        std::cout << "First number is larger!" << std::endl;
    }
    else
    {
        if (first < second)
        {
            std::cout << "Second number is larger!" << std::endl;
        }
        else
        {
            std::cout << "The numbers are equal!" << std::endl;
        }
    }

    return 0;
}
