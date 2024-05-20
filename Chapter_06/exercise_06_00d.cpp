// Exercise 6.0d
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <iostream>
#include <vector>
#include "Student.hpp"
#include "analysis.hpp"

bool didAllHomeworks(const Student& student)
{
    return std::find(student.homeworks.cbegin(), student.homeworks.cend(), 0.0) == student.homeworks.cend();
}

int main()
{
    std::vector<Student> studentsWithAllHomeworks;
    std::vector<Student> studentsWithoutAllHomeworks;

    Student s;
    while (read(std::cin, s))
    {
        if (didAllHomeworks(s))
        {
            studentsWithAllHomeworks.push_back(s);
        }
        else
        {
            studentsWithoutAllHomeworks.push_back(s);
        }
    }

    if (studentsWithAllHomeworks.empty())
    {
        std::cout << "There are no students with all homeworks done" << std::endl;
        return 1;
    }
    if (studentsWithoutAllHomeworks.empty())
    {
        std::cout << "Each student has done all the homeworks" << std::endl;
        return 1;
    }

    writeAnalysis(std::cout, "median", medianAnalysis, studentsWithAllHomeworks, studentsWithoutAllHomeworks);
    writeAnalysis(std::cout, "average", averageAnalysis, studentsWithAllHomeworks, studentsWithoutAllHomeworks);
    writeAnalysis(
        std::cout, "optimisticMedian", optimisticMedianAnalysis, studentsWithAllHomeworks, studentsWithoutAllHomeworks);

    return 0;
}
