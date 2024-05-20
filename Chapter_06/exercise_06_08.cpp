// Exercise 6.8
// Write a single function that can be used to classify students based on criteria of
// your choice. Test this function by using it in place of the extract_fails program, and
// use it in the program to analyze student grades.

#include <algorithm>
#include <iostream>
#include <vector>
#include "analysis.hpp"
#include "Student.hpp"

bool didAllHomeworks(const Student& student)
{
    return std::find(student.homeworks.cbegin(), student.homeworks.cend(), 0.0) == student.homeworks.cend();
}

std::vector<Student> extract(std::vector<Student>& students, bool extractCriteria(const Student&))
{
    const auto iter = std::stable_partition(students.begin(), students.end(), extractCriteria);
    const std::vector<Student> extractedStudents(iter, students.end());
    students.erase(iter, students.end());
    return extractedStudents;
}

int main()
{
    std::vector<Student> students;

    Student student;
    while (read(std::cin, student))
    {
        students.push_back(student);
    }
    const std::vector<Student> studentsWithoutAllHomeworks = extract(students, didAllHomeworks);
    const std::vector<Student>& studentsWithAllHomeworks = students;

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
    writeAnalysis(std::cout, "optimisticMedian", optimisticMedianAnalysis, studentsWithAllHomeworks, studentsWithoutAllHomeworks);

    return 0;
}
