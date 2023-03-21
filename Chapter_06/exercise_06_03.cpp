// Exercise 6.3
// What does this program fragment do?

#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> u(10, 100);
    std::vector<int> v;
    std::copy(u.begin(), u.end(), v.begin());

    // Program crashes.
    // Should be: std::copy(u.begin(), u.end(), std::back_inserter(v));
}
