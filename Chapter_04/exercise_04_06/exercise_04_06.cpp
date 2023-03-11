// Exercise 4.6
// Rewrite the Student_info structure to calculate the grades immediately and store only the final grade.

#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include "Student.hpp"

int main()
{
    std::vector<Student> students;

    Student student;
    std::string::size_type nameMaxLength = 0;
    while (std::cin)
    {
        read(std::cin, student);
        nameMaxLength = std::max(nameMaxLength, student.name.size());
        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), compare);

    std::cout << std::endl;

    std::streamsize prec = std::cout.precision(3);
    for (const auto& student: students)
    {
        std::cout << student.name << std::string(nameMaxLength - student.name.size() + 1, ' ') << student.finalGrade << std::endl;
    }
    std::cout.precision(prec);

    return 0;
}
