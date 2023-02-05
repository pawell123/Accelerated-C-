// Exercise 4.0
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include "grade.hpp"
#include "Student.hpp"

int main()
{
    std::vector<Student> students;

    Student student;
    std::string::size_type nameMaxLength = 0;
    while (read(std::cin, student))
    {
        nameMaxLength = std::max(nameMaxLength, student.name.size());
        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), compare);

    std::cout << std::endl;
    for (const auto& student: students)
    {
        std::cout << student.name << std::string(nameMaxLength - student.name.size() + 1, ' ');

        try
        {
            const double studentGrade = grade(student);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << studentGrade << std::setprecision(prec);

        } catch (const std::domain_error& error)
        {
            std::cout << error.what();
        }
        std::cout << std::endl;
    }

    return 0;
}
