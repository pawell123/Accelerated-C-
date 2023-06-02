// Exercise 4.3
// What happens if we rewrite the previous program to allow values up to but not including 1000
// but neglect to change the arguments to setw?
// Rewrite the program to be more robust in the face of changes that allow `i` to grow without adjusting the setw arguments.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

// 1st version
std::streamsize length(unsigned number)
{
    std::streamsize counter = 0;
    while (number > 0)
    {
        number /= 10;
        ++counter;
    }
    return counter;
}

// 2nd version
std::streamsize length2(unsigned number)
{
    return static_cast<std::streamsize>(std::to_string(number).size());
}

int main()
{
    const int range = 1000;
    const auto maxLength1 = length(range-1);             // length(range-1);
    const auto maxLength2 = length((range-1)*(range-1)); // length2((range-1)*(range-1))

    for (int i = 0; i != range; ++i)
    {
        std::cout << std::setw(maxLength1) << i << " " << std::setw(maxLength2) << i * i << std::endl;
    }

    return 0;
}
