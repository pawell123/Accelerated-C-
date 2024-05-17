// Exercise 5.3
// By using a typedef, we can write one version of the program
// that implements either a vector-based solution or a list-based one.
// Write and test this version of the program.

#include <iostream>
#include <list>
#include <vector>
#include "Student.hpp"
#include "grade.hpp"

// C++11
using StudentsContainer = std::vector<Student>; // using StudentsContainer = std::list<Student>;

// C++98
// typedef std::vector<Student> StudentsContainer; // typedef std::list<Student> StudentsContainer;

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
    const auto failedStudents = extract_fails(students);

    std::cout << "PASSED:\n";
    for (auto iter = students.cbegin(); iter != students.cend(); ++iter)
    {
        std::cout << iter->name << '\n';
    }

    std::cout << "\nFAILED:";
    for (auto iter = failedStudents.cbegin(); iter != failedStudents.cend(); ++iter)
    {
        std::cout << '\n' << iter->name;
    }
    std::cout << std::endl;

    return 0;
}
