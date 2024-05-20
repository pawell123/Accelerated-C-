// Exercise 6.0a
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <string>
#include "../common/split.hpp"

int main()
{
    const std::string str{"This is example sentence"};

    const auto splitted = split(str);

    for (const auto& word : splitted)
    {
        std::cout << word << '\n';
    }
    std::cout << std::flush;

    return 0;
}
