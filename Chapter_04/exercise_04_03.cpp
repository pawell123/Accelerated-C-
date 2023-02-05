// Exercise 4.3
// What happens if we rewrite the previous program to allow values up to but not including 1000
// but neglect to change the arguments to setw?
// Rewrite the program to be more robust in the face of changes that allow i to grow without adjusting the setw arguments.

#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    const int range = 1000;
    const auto maxValue1 = static_cast<int>(std::to_string(range-1).size());
    const auto maxValue2 = static_cast<int>(std::to_string((range-1)*(range-1)).size());

    for (int i = 0; i != range; ++i)
    {
        std::cout << std::setw(maxValue1) << i << " " << std::setw(maxValue2) << i * i << std::endl;
    }

    return 0;
}
