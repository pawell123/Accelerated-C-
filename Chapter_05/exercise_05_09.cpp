// Exercise 5.9
// Write a program to write the lowercase words in the input followed by the uppercase words.

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool containsUppercaseLetter(const std::string& str)
{
    for (auto c : str)
    {
        if (std::isupper(c))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<std::string> lowercaseVector;
    std::vector<std::string> uppercaseVector;

    std::string s;
    while (std::cin >> s)
    {
        if (containsUppercaseLetter(s))
        {
            uppercaseVector.push_back(s);
        }
        else
        {
            lowercaseVector.push_back(s);
        }
    }

    std::cout << std::endl << "Result: " << std::endl;

    for (const auto& word : lowercaseVector)
    {
        std::cout << word << std::endl;
    }

    for (const auto& word : uppercaseVector)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
