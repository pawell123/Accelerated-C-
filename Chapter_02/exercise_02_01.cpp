// Exercise 2.1
// Change the framing program so that it writes its greeting with no separation from the frame.

#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";

    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + '!';

    constexpr int pad = 0;
    constexpr int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;

    std::cout << '\n';

    for (int r = 0; r != rows; ++r)
    {
        std::string::size_type c = 0;

        while (c != cols)
        {
            if (r == pad + 1 && c == pad + 1)
            {
                std::cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << ' ';
                }
                ++c;
            }
        }
        std::cout << '\n';
    }
    std::cout << std::flush;

    return 0;
}
