// Exercise 6.1
// Reimplement the frame and hcat operations from §5.8.1/93 and §5.8.3/94 to use iterators.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>& vec)
{
    std::string::size_type maxWidth = 0;
    for (std::vector<std::string>::const_iterator iter = vec.cbegin(); iter != vec.cend(); ++iter)
    {
        maxWidth = std::max(maxWidth, iter->size());
    }
    return maxWidth;
}

std::vector<std::string> frame(const std::vector<std::string>& vec)
{
    std::vector<std::string> ret;

    const std::string::size_type maxWidth = width(vec);

    const std::string border(maxWidth + 4, '*');
    ret.push_back(border);
    for (std::vector<std::string>::const_iterator iter = vec.cbegin(); iter != vec.cend(); ++iter)
    {
        ret.push_back("* " + *iter + std::string(maxWidth - iter->size(), ' ') + " *");
    }
    ret.push_back(border);

    return ret;
}

std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right)
{
    std::vector<std::string> ret;

    const std::string::size_type leftWidth = width(left)+1;

    std::vector<std::string>::const_iterator leftIter = left.cbegin();
    std::vector<std::string>::const_iterator rightIter = right.cbegin();
    while (leftIter != left.cend() || rightIter != right.cend())
    {
        std::string line;
        if (leftIter != left.cend())
        {
            line = *leftIter++;
        }
        line += std::string(leftWidth - line.size(), ' ');

        if (rightIter != right.cend())
        {
            line += *rightIter++;
        }

        ret.push_back(line);
    }
    return ret;
}

int main()
{
    const std::vector<std::string> vec1{"aaa", "b", "cccccccccc", "ddddd", "ee", "ffffffff"};
    const std::vector<std::string> vec2{"ggggggg", "hh", "i", "jjjjjjjjjj", "kkk", "lllll"};

    const std::vector<std::string> framedHCat = frame(hcat(vec1, vec2));

    std::cout << std::endl;

    for (const auto& str : framedHCat)
    {
        std::cout << str << std::endl;
    }

    return 0;
}
