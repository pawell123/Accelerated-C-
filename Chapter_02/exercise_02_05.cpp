// Exercise 2.5
// Write a set of '*' characters so that they form a square, a rectangle, and a triangle.

#include <iostream>
#include <string>

void square(int sideLength)
{
    for (int i = 0; i != sideLength; ++i)
    {
        if (i == 0 || i == sideLength - 1)
        {
            std::cout << std::string(sideLength, '*');
        }
        else
        {
            std::cout << '*' + std::string(sideLength - 2, ' ') + '*';
        }
        std::cout << '\n';
    }
}

void rectangle(int height, int width)
{
    for (int i = 0; i != height; ++i)
    {
        if (i == 0 || i == height - 1)
        {
            std::cout << std::string(width, '*');
        }
        else
        {
            std::cout << '*' + std::string(width - 2, ' ') + '*';
        }
        std::cout << '\n';
    }
}

void triangle(int height)
{
    for (int h = 0; h != height; ++h)
    {
        if (h == 0)
        {
            std::cout << '*';
        }
        else if (h == height - 1)
        {
            std::cout << std::string(height, '*');
        }
        else
        {
            std::cout << '*' + std::string(h - 1, ' ') + '*';
        }
        std::cout << '\n';
    }
}

int main()
{
    square(5);
    std::cout << std::endl;

    rectangle(5, 10);
    std::cout << std::endl;

    triangle(10);
    std::cout << std::endl;

    return 0;
}
