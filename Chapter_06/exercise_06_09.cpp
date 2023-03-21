// Exercise 6.9
// Use a library algorithm to concatenate all the elements of a vector<string>.

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& vec)
{
    return std::accumulate(vec.cbegin(), vec.cend(), std::string{});
}

int main()
{
    const std::vector<std::string> vec{"aaa", "bbbb", "", "ccccc", "x"};

    std::cout << concatenate(vec) << std::endl;

    return 0;
}
