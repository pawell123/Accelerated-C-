// Exercise 5.10
// Palindromes are words that are spelled the same right to left as left to right.
// Write a program to find all the palindromes in a dictionary. Next, find the longest palindrome.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& str)
{
    return std::equal(str.cbegin(), str.cend(), str.crbegin(),
                      [](const auto a, const auto b) { return std::tolower(a) == std::tolower(b); });
}

// without using STL
bool isPalindrome2(const std::string& str)
{
    for (std::string::size_type i = 0, j = str.size()-1; i < j; ++i, --j)
    {
        if (std::tolower(str[i]) != std::tolower(str[j]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const std::vector<std::string> words{"afga", "asddsa", "asdsa", "x", "AbBa", "bbbbbb"};

    std::cout << "Palindromes: " << std::endl << std::endl;

    std::vector<std::string> longestPalindromes;
    for (const auto& word : words)
    {
        if (isPalindrome(word))
        {
            std::cout << word << std::endl;

            if (longestPalindromes.empty() || word.size() > longestPalindromes.front().size())
            {
                longestPalindromes =  std::vector<std::string>{word};
            }
            else if (word.size() == longestPalindromes.front().size())
            {
                longestPalindromes.push_back(word);
            }
        }
    }

    std::cout << std::endl << "Longest palindromes: " << std::endl;

    for (const auto& palindrome : longestPalindromes)
    {
        std::cout << palindrome << std::endl;
    }

    return 0;
}
