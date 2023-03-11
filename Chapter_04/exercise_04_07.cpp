// Exercise 4.7
// Write a program to calculate the average of the numbers stored in a vector<double>.

#include <iostream>
#include <numeric>
#include <vector>

double average1(const std::vector<double>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
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
    const std::vector<double> vec = { 1.0, 2.0, 3.0 };

    // First solution
    std::cout << "1) Average: " << average1(vec) << std::endl;

    // Second solution
    std::cout << "2) Average: " << average2(vec) << std::endl;

    return 0;
}
