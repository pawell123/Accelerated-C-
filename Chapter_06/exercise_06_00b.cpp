// Exercise 6.0b
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>

bool isPalindrome(const std::string& str)
{
    return std::equal(
        str.cbegin(),
        str.cend(),
        str.crbegin(),
        [](const auto left, const auto right) { return std::tolower(left) == std::tolower(right); });
}

int main()
{
    const std::array<std::string, 6> words{"a", "ab", "eYe", "AbBa", "asDffdSa", "asDfgdSa"};

    for (const auto& word : words)
    {
        if (isPalindrome(word))
        {
            std::cout << word << " is palindrome\n";
        }
        else
        {
            std::cout << word << " is not palindrome\n";
        }
    }
    std::cout << std::flush;

    return 0;
}
