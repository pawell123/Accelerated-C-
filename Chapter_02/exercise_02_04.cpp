// Exercise 2.4
// The framing program writes the mostly blank lines that separate the borders from the greeting one character at a time.
// Change the program so that it writes all the spaces needed in a single output expression.

#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";

    const int pad = 1;
    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;

    std::cout << std::endl;

    for (int r = 0; r != rows; ++r)
    {
        std::string::size_type c = 0;
        while (c != cols)
        {
            if (r == pad + 1 && c == 1)
            {
                std::cout << std::string(pad, ' ') + greeting + std::string(pad, ' ');
                c += greeting.size() + 2 * pad;
            }
            else
            {
                if (r == 0 || r == rows-1 || c == 0 || c == cols-1)
                {
                    std::cout << "*";
                    ++c;
                }
                else
                {
                    std::cout << std::string(cols - 2, ' ');
                    c += cols - 2;
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

