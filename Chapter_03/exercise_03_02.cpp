// Exercise 3.2
// Write a program to compute and print the quartiles (that is, the quarter of the numbers
// with the largest values, the next highest quarter, and so on) of a set of integers.

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

// https://en.wikipedia.org/wiki/Quartile - method 1
std::tuple<double, double, double> quartiles(std::vector<double> vec)
{
    std::sort(vec.begin(), vec.end());

    const double mid = vec.size() / 2;

    if (vec.size() % 2 == 0)
    {
        const double q1 = vec[mid / 2];
        const double q2 = (vec[mid] + vec[mid-1]) / 2;
        const double q3 = vec[mid + mid / 2];
        return std::make_tuple(q1, q2, q3);
    }
    const double q1 = vec[mid / 2];
    const double q2 = vec[mid];
    const double q3 = vec[(mid+1) + mid / 2];
    return std::make_tuple(q1, q2, q3);
}

int main()
{
    const std::vector<double> numbers1{7, 15, 36, 39, 40, 41};
    const auto quartiles1 = quartiles(numbers1);

    std::cout << std::get<0>(quartiles1) << " " << std::get<1>(quartiles1) << " " << std::get<2>(quartiles1) << std::endl;

    const std::vector<double> numbers2{ 6, 7, 15, 36, 39, 40, 41, 42, 43, 47, 49 };
    const auto quartiles2 = quartiles(numbers2);

    std::cout << std::get<0>(quartiles2) << " " << std::get<1>(quartiles2) << " " << std::get<2>(quartiles2) << std::endl;

    return 0;
}
