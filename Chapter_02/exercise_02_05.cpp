// Exercise 2.5
// Write a set of "*" characters so that they form a square, a rectangle, and a triangle.

#include <iostream>
#include <string>

void square()
{
    const int sideLength = 5;

    for (int i = 0; i != sideLength; ++i)
    {
        if (i == 0 || i == sideLength-1)
        {
            std::cout << std::string(sideLength, '*');
        }
        else
        {
            std::cout << "*" + std::string(sideLength-2, ' ') + "*";
        }
        std::cout << std::endl;
    }
}

void rectangle()
{
    const int height = 5;
    const int width = 10;

    for (int i = 0; i != height; ++i)
    {
        if (i == 0 || i == height-1)
        {
            std::cout << std::string(width, '*');
        }
        else
        {
            std::cout << "*" + std::string(width-2, ' ') + "*";
        }
        std::cout << std::endl;
    }
}

void triangle()
{
    const int height = 10;

    for (int h = 0; h != height; ++h)
    {
        if (h == 0)
        {
            std::cout << '*' << std::endl;
        }
        else if (h == 1)
        {
            std::cout << "**" << std::endl;
        }
        else if (h == height-1)
        {
            std::cout << std::string(height, '*') << std::endl;
        }
        else
        {
            std::cout << '*' + std::string(h-1, ' ') + '*';
            std::cout << std::endl;
        }
    }
}

int main()
{
    square();
    std::cout << std::endl;

    rectangle();
    std::cout << std::endl;

    triangle();

    return 0;
}
