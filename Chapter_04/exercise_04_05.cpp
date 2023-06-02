// Exercise 4.5
// Write a function that reads words from an input stream and stores them in a vector.
// Use that function both to write programs that count the number of words
// in the input, and to count how many times each word occurred.

#include <algorithm>
#include <iostream>
#include <string>
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

int main()
{
    std::vector<std::string> words = readWords(std::cin);

    std::cout << "Number of words: " << words.size() << std::endl;
    if (words.empty())
    {
        return 0;
    }

    std::sort(words.begin(), words.end());

    std::string previousWord;
    std::string::size_type counter = 0;

    for (std::string::size_type i = 0; i != words.size(); ++i)
    {
        const auto& currentWord = words[i];

        if (i == 0 || currentWord == previousWord)
        {
            ++counter;
        }
        else
        {
            std::cout << "Word: " << previousWord << ": " << counter << std::endl;
            counter = 1;
        }
        previousWord = currentWord;
    }
    std::cout << "Word: " << previousWord << ": " << counter << std::endl;

    return 0;
}
