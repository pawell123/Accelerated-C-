// Exercise 3.3
// Write a program to count how many times each distinct word appears in its input.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Write words: ";

    std::vector<std::string> words;
    std::string w;
    while (std::cin >> w)
    {
        words.push_back(w);
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

    if (!words.empty())
    {
        std::cout << "Word: " << words.back() << ": " << counter << std::endl;
    }

    return 0;
}
