// Exercise 4.2
// Write a program to calculate the squares of int values up to 100. The program should write two columns:
// The first lists the value; the second contains the square of that value.
// Use setw (described above) to manage the output so that the values line up in columns.

#include <iostream>
#include <iomanip>

int main()
{
    for (int i = 0; i != 101; ++i)
    {
        std::cout << std::setw(3) << i << " " << std::setw(5) << i * i << std::endl;
    }
    return 0;
}
