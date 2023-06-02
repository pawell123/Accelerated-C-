// Exercise 5.4
// Look again at the driver functions you wrote in the previous exercise. Note that it is
// possible to write a driver that differs only in the declaration of the type for the data
// structure that holds the input file. If your vector and list test drivers differ in any
// other way, rewrite them so that they differ only in this declaration.

#include <iostream>
#include <list>
#include <vector>
#include "grade.hpp"
#include "Student.hpp"

// C++11
using StudentsContainer = std::vector<Student>; // using StudentsContainer = std::list<Student>;

// C++98
// typedef std::vector<Student> StudentsContainer;      // typedef std::list<Student> StudentsContainer;

bool fgrade(const Student& student)
{
    return grade(student) < 60;
}

StudentsContainer extract_fails(StudentsContainer& students)
{
    StudentsContainer fails;

    StudentsContainer::iterator iter = students.begin();
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

int main()
{
    const Student student1{"John", 1, 1, {1, 2}};
    const Student student2{"Paul", 100, 100, {100, 200}};
    const Student student3{"Peter", 1, 1, {1, 2}};
    const Student student4{"Robert", 111, 222, {333, 444}};

    StudentsContainer students{student1, student2, student3, student4};
    const StudentsContainer failedStudents = extract_fails(students);

    std::cout << "PASSED: " << std::endl;
    for (StudentsContainer::const_iterator iter = students.cbegin(); iter != students.cend(); ++iter)
    {
        std::cout << iter->name << std::endl;
    }

    std::cout << std::endl << "FAILED: " << std::endl;
    for (StudentsContainer::const_iterator iter = failedStudents.cbegin(); iter != failedStudents.cend(); ++iter)
    {
        std::cout << iter->name << std::endl;
    }

    return 0;
}
