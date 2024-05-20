// Exercise 6.0e
// Compile, execute, and test the programs in this chapter.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "Student.hpp"
#include "grade.hpp"

bool isFailedStudent(const Student& student)
{
    return grade(student) < 60;
}

bool isPassedStudent(const Student& student)
{
    return !isFailedStudent(student);
}

std::vector<Student> extractFails1(std::vector<Student>& students)
{
    std::vector<Student> failedStudents;
    std::remove_copy_if(students.cbegin(), students.cend(), std::back_inserter(failedStudents), isPassedStudent);
    const std::vector<Student>::iterator iter = std::remove_if(students.begin(), students.end(), isFailedStudent);
    students.erase(iter, students.end());

    return failedStudents;
}

std::vector<Student> extractFails2(std::vector<Student>& students)
{
    const std::vector<Student>::iterator iter =
        std::stable_partition(students.begin(), students.end(), isPassedStudent);
    std::vector<Student> failedStudents(iter, students.end());
    students.erase(iter, students.end());

    return failedStudents;
}

int main()
{
    const Student student1{"student1", 1, 1, {1, 1, 1}};
    const Student student2{"student2", 100, 200, {100, 200, 300}};
    const Student student3{"student3", 1, 1, {1, 1, 1}};
    const Student student4{"student4", 1, 1, {1, 1, 1}};
    const Student student5{"student5", 100, 200, {100, 200, 300}};
    const Student student6{"student6", 1, 1, {1, 1, 1}};
    const Student student7{"student7", 100, 200, {100, 200, 300}};

    std::vector<Student> students{student1, student2, student3, student4, student5, student6, student7};

    const std::vector<Student> failedStudents = extractFails2(students); // extractFails1(students);

    std::cout << "Failed students: ";
    for (const Student& student : failedStudents)
    {
        std::cout << '\n' << student.name;
    }

    std::cout << std::endl << "\n\nPassed students: ";
    for (const Student& student : students)
    {
        std::cout << '\n' << student.name;
    }
    std::cout << std::endl;

    return 0;
}
