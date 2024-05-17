// Exercise 4.4
// Now change your squares program to use double values instead of ints.
// Use manipulators to manage the output so that the values line up in columns.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main()
{
    constexpr int range = 1000;
    const int maxLength1 = static_cast<int>(std::to_string(range-1).size());
    const int maxLength2 = static_cast<int>(std::to_string((range-1)*(range-1)).size());

    const std::streamsize prec = std::cout.precision(0);
    for (double i = 0; i != range; ++i)
    {
        std::cout << std::fixed << std::setw(maxLength1) << i << ' ' << std::setw(maxLength2) << i * i << '\n';
    }
    std::cout << std::setprecision(prec) << std::flush;

    return 0;
}
