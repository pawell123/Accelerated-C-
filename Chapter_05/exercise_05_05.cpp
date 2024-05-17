// Exercise 5.5
// Write a function named center(const vector<string>&) that returns a picture
// in which all the lines of the original picture are padded out to their full width,
// and the padding is as evenly divided as possible between the left and right sides of the picture.
// What are the properties of pictures for which such a function is useful?
// How can you tell whether a given picture has those properties?

// Answer: It is useful when difference between the longest string and every other string is even number.

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string::size_type maxLength(const std::vector<std::string>& vec)
{
    std::string::size_type maxLen = 0;
    for (const auto& str : vec)
    {
        maxLen = std::max(maxLen, str.size());
    }
    return maxLen;
}

std::vector<std::string> center(const std::vector<std::string>& pic)
{
    std::vector<std::string> ret;

    const std::vector<std::string>::size_type maxLen = maxLength(pic);

    for (const auto& line : pic)
    {
        const std::vector<std::string>::size_type difference = maxLen - line.size();
        const std::vector<std::string>::size_type leftPad = difference / 2;
        const std::vector<std::string>::size_type rightPad = (difference % 2 == 0) ? leftPad : (leftPad + 1);

        ret.push_back(std::string(leftPad, ' ') + line + std::string(rightPad, ' '));
    }
    return ret;
}

int main()
{
    const std::vector<std::string> goodPicture = center(std::vector<std::string>{"aa", "bbbbbbbbbb", "cccccc", "dddd"});
    const std::vector<std::string> badPicture = center(std::vector<std::string>{"eee", "ffffffffff", "ggggg", "hhhh"});

    for (const auto& line : goodPicture)
    {
        std::cout << line << '\n';
    }

    for (const auto& line : badPicture)
    {
        std::cout << '\n' << line;
    }
    std::cout << std::endl;

    return 0;
}
