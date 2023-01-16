// Exercise 2.8
// Write a program to generate the product of the numbers in the range [1, 10) .

#include <iostream>
#include <string>

int main()
{
    for (int i = 1; i != 10; ++i)
    {
        for (int j = i; j != 10; ++j)
        {
            std::cout << i*j << std::endl;
        }
    }

    return 0;
}
