// Exercise 5.3
// By using a typedef, we can write one version of the program
// that implements either a vector-based solution or a list-based one.
// Write and test this version of the program.

#include <iostream>
#include <list>
#include <vector>
#include "grade.hpp"
#include "Student.hpp"

// C++11
using StudentsContainer = std::vector<Student>; // using Container = std::list<Student>;

// C++98
// typedef std::vector<Student> Container;      // typedef std::list<Student> Container;

bool fgrade(const Student& student)
{
    return grade(student) < 60;
}

StudentsContainer extract_fails4(StudentsContainer& students)
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
    const StudentsContainer failedStudents = extract_fails4(students);

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
