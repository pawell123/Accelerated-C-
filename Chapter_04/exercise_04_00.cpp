// Exercise 4.0
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Student.hpp"
#include "grade.hpp"

int main()
{
    std::vector<Student> students;

    Student s;
    std::string::size_type nameMaxLength = 0;
    while (read(std::cin, s))
    {
        nameMaxLength = std::max(nameMaxLength, s.name.size());
        students.push_back(s);
    }

    std::sort(students.begin(), students.end(), compare);

    for (const auto& student : students)
    {
        std::cout << '\n' << student.name << std::string(nameMaxLength - student.name.size() + 1, ' ');

        try
        {
            const double studentGrade = grade(student);
            const std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << studentGrade << std::setprecision(prec);
        }
        catch (const std::domain_error& error)
        {
            std::cout << error.what();
        }
    }
    std::cout << std::endl;

    return 0;
}
