// Exercise 5.1
/*
Design and implement a program to produce a permuted index. A permuted index is one in which each phrase is indexed by
every word in the phrase. So, given the following input:

    The quick brown fox
    jumped over the fence

the output would be

    The quick           brown fox
    jumped over the     fence
    The quick brown     fox
                        jumped over the fence
    jumped              over the fence
    The                 quick brown fox
    jumped over         the fence
                        The quick brown fox

A good algorithm is suggested in The AWK Programming Language by Aho, Kernighan, and Weinberger (Addison-Wesley, 1988).
That solution divides the problem into three steps:

1. Read each line of the input and generate a set of rotations of that line. Each rotation puts the next word of the
input in the first position and rotates the previous first word to the end of the phrase. So the output of this phase
for the first line of our input would be:

    The quick brown fox
    quick brown fox The
    brown fox The quick
    fox The quick brown

Of course, it will be important to know where the original phrase ends and where the rotated beginning begins.

2. Sort the rotations.

3. Unrotate and write the permuted index, which involves finding the separator, putting the phrase back together, and
writing it properly formatted.
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <utility>
#include <vector>

namespace
{
const std::string delimiter{};
}

using UnsplittedLines = std::vector<std::string>;
using SplittedLine = std::list<std::string>;
using SplittedLines = std::vector<SplittedLine>;

SplittedLine splitLine(const std::string& unsplittedLine)
{
    SplittedLine ret;

    auto iterLeft = unsplittedLine.cbegin();
    while (iterLeft != unsplittedLine.cend())
    {
        iterLeft = std::find_if(iterLeft, unsplittedLine.cend(), [](const auto c) { return !std::isspace(c); });
        const auto iterRight =
            std::find_if(iterLeft, unsplittedLine.cend(), [](const auto c) { return std::isspace(c); });
        if (iterLeft != iterRight)
        {
            ret.push_back(std::string(iterLeft, iterRight));
            iterLeft = iterRight;
        }
    }
    return ret;
}

SplittedLines splitLines(const UnsplittedLines& unsplittedLines)
{
    SplittedLines ret;
    std::transform(
        unsplittedLines.cbegin(),
        unsplittedLines.cend(),
        std::back_inserter(ret),
        [](const auto& line) { return splitLine(line); });
    return ret;
}

void addDelimiters(SplittedLines& splittedLines)
{
    for (auto& line : splittedLines)
    {
        line.push_back(delimiter);
    }
}

bool isDelimiter(const std::string& str)
{
    return str == delimiter;
}

SplittedLine toLower(const SplittedLine& line)
{
    SplittedLine ret;

    for (const auto& word : line)
    {
        std::string lowerWord;
        std::transform(
            word.cbegin(), word.cend(), std::back_inserter(lowerWord), [](const char c) { return std::tolower(c); });
        ret.push_back(lowerWord);
    }
    return ret;
}

SplittedLines rotate(const SplittedLines& input)
{
    SplittedLines ret;

    for (auto line : input)
    {
        do
        {
            const auto firstElement = line.front();
            line.erase(line.begin());
            if (isDelimiter(line.front()))
            {
                line.erase(line.begin());
                line.push_back(firstElement);
                line.push_back(delimiter);
            }
            else
            {
                line.push_back(firstElement);
            }
            ret.push_back(line);

        } while (!isDelimiter(line.back()));
    }
    std::sort(ret.begin(), ret.end(), [](const auto& lhs, const auto& rhs) { return toLower(lhs) < toLower(rhs); });
    return ret;
}

std::vector<std::pair<SplittedLine, SplittedLine>> unrotate(const SplittedLines& lines)
{
    std::vector<std::pair<SplittedLine, SplittedLine>> ret;
    for (const auto& line : lines)
    {
        const auto iter = std::find(line.cbegin(), line.cend(), delimiter);
        if (iter != line.cend())
        {
            ret.push_back(
                std::make_pair(SplittedLine(std::next(iter), line.cend()), SplittedLine(line.cbegin(), iter)));
        }
    }
    return ret;
}

std::vector<std::pair<SplittedLine, SplittedLine>> permutedIndex(const UnsplittedLines& unsplittedLines)
{
    SplittedLines splittedLines = splitLines(unsplittedLines);
    addDelimiters(splittedLines);
    splittedLines = rotate(splittedLines);
    return unrotate(splittedLines);
}

int main()
{
    const UnsplittedLines unsplittedLines = {"The quick brown fox", "jumped over the fence"};

    const auto permutedIdx = permutedIndex(unsplittedLines);

    for (const auto& line : permutedIdx)
    {
        for (const auto& partBeforeKeyword : line.first)
        {
            std::cout << partBeforeKeyword << ' ';
        }

        std::cout << "--";

        for (const auto& partWithKeyword : line.second)
        {
            std::cout << ' ' << partWithKeyword;
        }

        std::cout << '\n';
    }
    std::cout << std::flush;

    return 0;
}
