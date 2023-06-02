// Exercise 3.4
// Write a program to report the length of the longest and shortest string in its input.

#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter words: ";

    std::string word;

    std::string::size_type longestWordSize = 0;
    std::string::size_type shortestWordSize = word.max_size();

    while (std::cin >> word)
    {
        const std::string::size_type currentSize = word.size();

        shortestWordSize = std::min(currentSize, shortestWordSize);
        longestWordSize = std::max(currentSize, longestWordSize);
    }

    if (longestWordSize == 0)
    {
        std::cerr << "No input!" << std::endl;
        return 1;
    }

    std::cout << "Shortest word size: " << shortestWordSize << std::endl;
    std::cout << "Longest word size: " << longestWordSize << std::endl;

    return 0;
}
