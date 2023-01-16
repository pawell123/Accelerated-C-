// Exercise 2.2
// Change the framing program so that it uses a different amount of space to separate the sides
// from the greeting than it uses to separate the top and bottom borders from the greeting.

#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";

    const int rowsPad = 1;
    const int colsPad = 5;

    const int rows = rowsPad * 2 + 3;
    const std::string::size_type cols = greeting.size() + colsPad * 2 + 2;

    std::cout << std::endl;

    for (int r = 0; r != rows; ++r)
    {
        std::string::size_type c = 0;
        while (c != cols)
        {
            if (r == rowsPad + 1 && c == colsPad+1)
            {
                std::cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows-1 || c == 0 || c == cols-1)
                {
                    std::cout << "*";
                }
                else
                {
                    std::cout << " ";
                }
                ++c;
            }
        }
        std::cout << std::endl;
    }
}
