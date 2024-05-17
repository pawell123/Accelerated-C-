// Exercise 4.3
// What happens if we rewrite the previous program to allow values up to but not including 1000
// but neglect to change the arguments to setw?
// Rewrite the program to be more robust in the face of changes that allow `i` to grow without adjusting the setw
// arguments.

#include <iomanip>
#include <iostream>
#include <string>

// 1st version
int length(unsigned number)
{
    int counter = 0;
    while (number > 0)
    {
        number /= 10;
        ++counter;
    }
    return counter;
}

// 2nd version
int length2(unsigned number)
{
    return static_cast<int>(std::to_string(number).size());
}

int main()
{
    const int range = 1000;
    const int maxLength1 = length(range - 1); // length2(range - 1);
    const int maxLength2 = length((range - 1) * (range - 1)); // length2((range - 1) * (range - 1))

    for (int i = 0; i != range; ++i)
    {
        std::cout << std::setw(maxLength1) << i << ' ' << std::setw(maxLength2) << i * i << '\n';
    }
    std::cout << std::setw(0) << std::flush;

    return 0;
}
