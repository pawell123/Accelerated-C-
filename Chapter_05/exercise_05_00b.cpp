// Example 5.0b
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> ret;

    std::string::size_type i = 0;
    while (i != str.size())
    {
        while (i != str.size() && std::isspace(str[i]))
        {
            ++i;
        }

        std::string::size_type j = i;

        while (j != str.size() && !std::isspace(str[j]))
        {
            ++j;
        }

        if (i != j)
        {
            ret.push_back(str.substr(i, j-i));
            i = j;
        }
    }
    return ret;
}

int main()
{
    std::string str;
    while (std::getline(std::cin, str))
    {
        std::vector<std::string> words = split(str);

        for (std::vector<std::string>::const_iterator iter = words.cbegin(); iter != words.cend(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }

    return 0;
}
