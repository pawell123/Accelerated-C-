// Exercise 3.4
// Write a program to report the length of the longest and shortest string in its input.

#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter words: ";

    std::string word;

    std::string::size_type longest = 0;
    std::string::size_type shortest = word.max_size();

    while (std::cin >> word)
    {
        const std::string::size_type currentSize = word.size();

        shortest = std::min(currentSize, shortest);
        longest = std::max(currentSize, longest);
    }

    if (longest == 0)
    {
        std::cout << "No input!" << std::endl;
        return 1;
    }

    std::cout << "Shortest word size: " << shortest << std::endl;
    std::cout << "Longest word size: " << longest << std::endl;

    return 0;
}
