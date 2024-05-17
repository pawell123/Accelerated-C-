// Exercise 4.6
// Rewrite the Student_info structure to calculate the grades immediately and store only the final grade.

#include <algorithm>
#include <iomanip>
#include <ios>
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

    const std::streamsize prec = std::cout.precision(3);
    for (const auto& s : students)
    {
        std::cout << s.name << std::string(nameMaxLength - s.name.size() + 1, ' ') << s.finalGrade << '\n';
    }
    std::cout << std::setprecision(prec) << std::flush;

    return 0;
}
