// Exercise 5.7
// Given the implementation of frame in §5.8.1/93, and the following code fragment

// vector<string> v;
// frame(v);

// describe what happens in this call. In particular, trace through how both the width
// function and the frame function operate. Now, run this code. If the results differ from
// your expectations, first understand why your expectations and the program differ, and
// then change one to match the other.

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

int main()
{
    std::vector<std::string> v;
    frame(v);

    return 0;
}
