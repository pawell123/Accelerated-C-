// Exercise 6.0a
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool isSpace(char c)
{
    return std::isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> ret;

    auto iter1 = str.cbegin();
    while (iter1 != str.cend())
    {
        iter1 = std::find_if_not(iter1, str.cend(), isSpace);

        const auto iter2 = std::find_if(iter1, str.cend(), isSpace);

        if (iter1 != iter2)
        {
            ret.push_back(std::string(iter1, iter2));
        }
        iter1 = iter2;
    }

    return ret;
}

int main()
{
    const std::string str{"This is example sentence"};

    const auto splitted = split(str);

    for (const auto& word : splitted)
    {
        std::cout << word << std::endl;
    }
    return 0;
}
