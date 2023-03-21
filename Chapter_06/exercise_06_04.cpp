// Exercise 6.4
// Correct the program you wrote in the previous exercise to copy from u into v.
// There are at least two possible ways to correct the program. Implement both, and
// describe the relative advantages and disadvantages of each approach.

#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
    // std::vector<int> u(10, 100);
    // std::vector<int> v;
    // std::copy(u.begin(), u.end(), v.begin());

    // Version 1
    const std::vector<int> u(10, 100);
    std::vector<int> v;
    std::copy(u.cbegin(), u.cend(), std::back_inserter(v));

    // Version 2
    const std::vector<int> u2(10, 100);
    std::vector<int> v2;
    v.insert(v2.end(), u2.cbegin(), u2.cend());

    return 0;
}
