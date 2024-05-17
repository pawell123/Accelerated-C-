// Exercise 5.8
// In the hcat function from §5.8.3/95, what would happen if we defined s outside
// the scope of the while? Rewrite and execute the program to confirm your hypothesis.

// Answer: The problem is when right vector is larger than left one - undefined behavior for
//         "line += std::string(leftWidth - line.size(), ' ');"
//         1) unexpected exception: 'std::length_error' OR
//         2) improper behavior - a lot of spaces

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>& vec)
{
    std::string::size_type maxWidth = 0;
    for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
    {
        maxWidth = std::max(maxWidth, iter->size());
    }
    return maxWidth;
}

std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right)
{
    std::vector<std::string> ret;

    const std::string::size_type leftWidth = width(left) + 1;

    std::vector<std::string>::const_iterator leftIter = left.cbegin();
    std::vector<std::string>::const_iterator rightIter = right.cbegin();

    std::string line;
    while (leftIter != left.cend() || rightIter != right.cend())
    {
        // std::string line;
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
    const std::vector<std::string> left{"one", "two", "three"};
    const std::vector<std::string> right{"four", "five", "six", "seven", "eight", "nine", "ten"};

    const std::vector<std::string> vec = hcat(left, right);

    for (const auto& line : vec)
    {
        std::cout << line << '\n';
    }
    std::cout << std::flush;

    return 0;
}
