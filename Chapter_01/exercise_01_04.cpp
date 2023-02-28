// Exercise 1.4
// What about this one? What if we change }} to };} in the third line from the end?

#include <iostream>
#include <string>

int main()
{
    { const std::string s = "a string";
      std::cout << s << std::endl;
    { const std::string s = "another string";
      std::cout << s << std::endl; }}

    return 0;
}

// The code is valid.
// The code is also valid with };} in the fourth line from the end (a null statement will be added).
