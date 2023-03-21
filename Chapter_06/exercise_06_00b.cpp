// Exercise 6.0b
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

bool isPalindrome(const std::string& str)
{
    return std::equal(str.cbegin(), str.cend(), str.crbegin(), [](const auto l, const auto r) { return std::tolower(l) == std::tolower(r); });
}

int main()
{
    const std::vector<std::string> words{ "a", "ab", "eYe", "AbBa", "asDffdSa", "asDfgdSa" };

    for (const auto& word : words)
    {
        if (isPalindrome(word))
        {
            std::cout << word << " is palindrome" << std::endl;
        }
        else
        {
            std::cout << word << " is not palindrome" << std::endl;
        }
    }
    return 0;
}
