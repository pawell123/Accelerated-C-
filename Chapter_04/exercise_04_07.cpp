// Exercise 4.7
// Write a program to calculate the average of the numbers stored in a vector<double>.

#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<double> vec = { 1.0, 2.0, 3.0 };

    std::cout << "1) Average: " << std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size() << std::endl;

    // or

    double sum = 0.0;
    for (auto elem : vec)
    {
        sum += elem;
    }

    std::cout << "2) Average: " << sum / vec.size() << std::endl;

    return 0;
}
