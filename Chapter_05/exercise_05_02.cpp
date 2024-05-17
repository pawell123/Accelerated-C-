// Exercise 5.2
// Write the complete new version of the student-grading program, which extracts
// records for failing students, using vectors. Write another that uses lists. Measure
// the performance difference on input files of ten lines, 1,000 lines, and 10,000 lines.

#include <array>
#include <chrono>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <list>
#include <vector>
#include "Student.hpp"

bool fgrade(const Student& student)
{
    return static_cast<bool>(rand() % 2);
}

template <typename Students>
Students extractFails(Students& students)
{
    Students fails;

    typename Students::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fails.push_back(*iter);
            iter = students.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return fails;
}

template <typename Students>
std::chrono::duration<double> measure(Students students)
{
    std::srand(0);
    const auto start = std::chrono::high_resolution_clock::now();

    extractFails(students);

    const auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double>(stop - start);
}

int main()
{
    constexpr std::array<int, 3> sizes = {10, 1000, 10000};

    const Student exampleStudent{"Name", 1, 2, {3, 4, 5}};

    std::cout << std::fixed;
    for (const auto size : sizes)
    {
        std::cout << "Size: " << size << '\n';

        const std::vector<Student> studentsVec(size, exampleStudent);
        std::cout << "Type std::vector<Student>: " << measure(studentsVec).count() << "s\n";

        const std::list<Student> studentsList(size, exampleStudent);
        std::cout << "Type std::list<Student>:   " << measure(studentsList).count() << "s\n" << std::endl;
    }

    return 0;
}
