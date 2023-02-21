// Exercise 5.10
// Palindromes are words that are spelled the same right to left as left to right.
// Write a program to find all the palindromes in a dictionary. Next, find the longest palindrome.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(const std::string& s)
{
    return std::equal(s.cbegin(), s.cend(), s.rbegin(),
                      [](const auto a, const auto b) { return std::tolower(a) == std::tolower(b); });
}

int main()
{
    std::vector<std::string> words{"afga", "asddsa", "asdsa", "x", "AbBa", "bbbbbb"};

    std::cout << "Palindromes: " << std::endl << std::endl;

    std::vector<std::string> longestPalindromes;
    for (const auto& word : words)
    {
        if (is_palindrome(word))
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
