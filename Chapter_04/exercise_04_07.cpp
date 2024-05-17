// Exercise 4.7
// Write a program to calculate the average of the numbers stored in a vector<double>.

#include <iostream>
#include <numeric>
#include <vector>

double average1(const std::vector<double>& vec)
{
    return std::accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();
}

double average2(const std::vector<double>& vec)
{
    double sum = 0.0;
    for (const auto elem : vec)
    {
        sum += elem;
    }
    return sum / vec.size();
}

int main()
{
    const std::vector<double> vec = {1.0, 2.0, 3.0, 4.0};

    std::cout << "Average: " << average1(vec) << std::endl; // average2(vec)

    return 0;
}
