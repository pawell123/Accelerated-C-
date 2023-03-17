// Exercise 5.6
// Rewrite the extract_fails function from §5.1.1/77 so that instead of erasing each failing student from the input vector v,
// it copies the records for the passing students to the beginning of v, and then uses the resize function to remove the extra
// elements from the end of v.
// How does the performance of this version compare with the one in §5.1.1/77?

// Performance in this exercise is better than the previous one.

#include <algorithm>
#include <iostream>
#include <vector>
#include "Student.hpp"
#include "grade.hpp"

bool fgrade(const Student& s)
{
    return grade(s) < 60;
}

bool pgrade(const Student& s)
{
    return !fgrade(s);
}

std::vector<Student> extract_fails(std::vector<Student>& students)
{
    std::vector<Student>::iterator iterPassed = students.begin();
    std::vector<Student>::iterator iter = students.begin();

    while (iter != students.end())
    {
        iterPassed = std::find_if(students.begin(), students.end(), fgrade);
        iter = std::find_if(iterPassed, students.end(), pgrade);

        if (iter != students.end())
        {
            std::swap(*iterPassed, *iter);
        }
    }

    const std::vector<Student> failed(iterPassed, students.end());
    students.resize(iterPassed - students.begin());

    return failed;
}

std::vector<Student> extract_fails_without_stl(std::vector<Student>& students)
{
    std::vector<Student>::iterator iterPassed = students.begin();
    std::vector<Student>::iterator iter = students.begin();

    while (iter != students.end())
    {
        while (iterPassed != students.end() && pgrade(*iterPassed))
        {
            ++iterPassed;
        }

        iter = iterPassed;

        while (iter != students.end() && fgrade(*iter))
        {
            ++iter;
        }

        if (iter != students.end())
        {
            const auto temp = *iterPassed;
            *iterPassed = *iter;
            *iter = temp;
        }
    }

    const std::vector<Student> failed(iterPassed, students.end());
    students.resize(iterPassed - students.begin());

    return failed;
}

int main()
{
    std::cout << "Test:" << std::endl << std::endl;

    std::vector<Student> students{Student{"One", 1, 2, {3}},
                                  Student{"Two", 1000, 2000, {3000}},
                                  Student{"Three", 434, 543, {1432}},
                                  Student{"Four", 2, 2, {2}},
                                  Student{"Five", 3, 4, {5}},
                                  Student{"Six", 5, 7, {8}},
                                  Student{"Seven", 543, 86, {55}},
                                  Student{"Eight", 1, 1, {1}},
                                  Student{"Nine", 54, 55, {2}},
                                  Student{"Ten", 43, 535, {60}}};

    const auto failed = extract_fails(students);

    std::cout << "Passed: " << std::endl;
    for (const auto& s : students)
    {
        std::cout << "+ " << s.name << " " << grade(s) << std::endl;
    }

    std::cout << std::endl << "Failed: " << std::endl;
    for (const auto& s : failed)
    {
        std::cout << "- " << s.name << " " << grade(s) << std::endl;
    }

    return 0;
}
