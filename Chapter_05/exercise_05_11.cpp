// Exercise 5.11
// In text processing it is sometimes useful to know whether a word has any ascenders or descenders.
// Ascenders are the parts of lowercase letters that extend above the text line;
// in the English alphabet, the letters b, d, f, h, k, l, and t have ascenders.
// Similarly, the descenders are the parts of lowercase letters that descend below the line;
// In English, the letters g, j, p, q, and y have descenders.
// Write a program to determine whether a word has any ascenders or descenders.
// Extend that program to find the longest word in the dictionary that has neither ascenders nor descenders.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isAscender(char c)
{
    static const std::string ascenders = "bdfhklt";
    return std::find(ascenders.cbegin(), ascenders.cend(), c) != ascenders.cend();
}

bool hasAscenders(const std::string& str)
{
    return std::find_if(str.cbegin(), str.cend(), isAscender) != str.cend();
}

bool isDescender(char c)
{
    static const std::string descenders = "gjpqy";
    return std::find(descenders.cbegin(), descenders.cend(), c) != descenders.cend();
}

bool hasDescenders(const std::string& str)
{
    return std::find_if(str.cbegin(), str.cend(), isDescender) != str.cend();
}

int main()
{
    const std::vector<std::string> words{"fewfew", "aaaccc", "agt", "fff", "actca", "c", "acacac", "eeeee"};
    std::vector<std::string> longestWordsWithoutAscendersNorDescenders;

    for (const auto& word : words)
    {
        if (hasAscenders(word) || hasDescenders(word))
        {
            std::cout << "Word: " << word << " has ascenders/descenders" << std::endl;
        }
        else
        {
            if (longestWordsWithoutAscendersNorDescenders.empty() || longestWordsWithoutAscendersNorDescenders.front().size() == word.size())
            {
                longestWordsWithoutAscendersNorDescenders.push_back(word);
            }
            else if (word.size() > longestWordsWithoutAscendersNorDescenders.front().size())
            {
                longestWordsWithoutAscendersNorDescenders = std::vector<std::string>{word};
            }
        }
    }

    if (!longestWordsWithoutAscendersNorDescenders.empty())
    {
        std::cout << std::endl << "Longest words without ascenders nor descenders are: " << std::endl;
        for (const auto& word : longestWordsWithoutAscendersNorDescenders)
        {
            std::cout << word << std::endl;
        }
    }
    else
    {
        std::cout << "No words without ascendrs/descenders" << std::endl;
    }

    return 0;
}
