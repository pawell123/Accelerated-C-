// Exercise 4.4
// Now change your squares program to use double values instead of ints.
// Use manipulators to manage the output so that the values line up in columns.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main()
{
    const int range = 1000;
    const auto maxValue1 = static_cast<int>(std::to_string(range-1).size());
    const auto maxValue2 = static_cast<int>(std::to_string((range-1)*(range-1)).size());

    const std::streamsize prec = std::cout.precision();
    for (int i = 0; i != range; ++i)
    {
        std::cout << std::fixed << std::setw(maxValue1) << std::setprecision(0) << static_cast<double>(i) << " " << std::setw(maxValue2)
                  << static_cast<double>(i) * static_cast<double>(i) << std::endl;
    }
    std::cout.precision(prec);

    return 0;
}
