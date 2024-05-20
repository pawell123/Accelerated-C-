// Exercise 6.7
// The portion of the grading analysis program from §6.2.1/110 that read and classified student records depending on
// whether they did (or did not) do all the homework is similar to the problem we solved in extract_fails. Write a
// function to handle this subproblem.

#include <algorithm>
#include <vector>
#include "Student.hpp"

bool didAllHomeworks(const Student& student)
{
    const auto& homeworks = student.homeworks;
    return std::find(homeworks.cbegin(), homeworks.cend(), 0.0) == homeworks.cend();
}

std::vector<Student> extractStudentsWithoutAllHomeworks(std::vector<Student>& students)
{
    const auto iter = std::stable_partition(students.begin(), students.end(), didAllHomeworks);
    const std::vector<Student> studentsWithoutAllHomeworks(iter, students.end());
    students.erase(iter, students.end());
    return studentsWithoutAllHomeworks;
}
