// Exercise 4.1
// We noted in §4.2.3/65 that it is essential that the argument types in a call to max
// match exactly. Will the following code work? If there is a problem, how would you fix it?

#include <algorithm>
#include <string>
#include "Student.hpp"

int main()
{
    /*
        int maxlen;
        Student s;
        std::max(s.name.size(), maxlen);
    */
    // Above code is not correct (cannot deduce return type)

    std::string::size_type maxlen = 0;
    Student s;
    std::max(s.name.size(), maxlen);

    return 0;
}
