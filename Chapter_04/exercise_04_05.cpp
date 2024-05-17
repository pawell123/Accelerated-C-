// Exercise 4.5
// Write a function that reads words from an input stream and stores them in a vector.
// Use that function both to write programs that count the number of words
// in the input, and to count how many times each word occurred.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> readWords(std::istream& in)
{
    std::vector<std::string> ret;

    std::string word;
    while (in >> word)
    {
        ret.push_back(word);
    }
    return ret;
}

// Version 1
std::vector<std::pair<std::string, int>> countWords1(std::vector<std::string> words)
{
    std::vector<std::pair<std::string, int>> ret;
    if (words.empty())
    {
        return ret;
    }

    std::sort(words.begin(), words.end());

    std::string previousWord;
    int counter = 0;

    for (std::string::size_type i = 0; i != words.size(); ++i)
    {
        const auto& currentWord = words[i];

        if (i == 0 || currentWord == previousWord)
        {
            ++counter;
        }
        else
        {
            ret.emplace_back(std::make_pair(previousWord, counter));
            counter = 1;
        }
        previousWord = currentWord;
    }
    ret.emplace_back(std::make_pair(words.back(), counter));
    return ret;
}

// Version 2
std::map<std::string, int> countWords2(const std::vector<std::string>& words)
{
    std::map<std::string, int> ret;

    for (const auto& word : words)
    {
        ++ret[word];
    }
    return ret;
}

int main()
{
    auto words = readWords(std::cin);
    std::cout << "\nNumber of words: " << words.size() << std::endl;

    std::cout << "\nWords:";
    const auto wordsCounters = countWords1(std::move(words)); // countWords2(std::cin)
    for (const auto& item : wordsCounters)
    {
        std::cout << '\n' << item.first << ": " << item.second;
    }
    std::cout << std::endl;

    return 0;
}
