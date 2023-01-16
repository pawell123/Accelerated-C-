// Exercise 2.10
// Explain each of the uses of std:: in the following program:

#include <iostream>

int main()
{
    const int n = 10;
    int k = 0;
    while (k != n)
    {
        using std::cout;    // using-declaration is valid only in the loop body
        cout << "*";
        ++k;
    }
    std::cout << std::endl; // std:: is required here

    return 0;
}
