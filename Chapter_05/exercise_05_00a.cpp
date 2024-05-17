// Exercise 5.0a
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <list>
#include "Student.hpp"
#include "grade.hpp"

bool fgrade(const Student& student)
{
    return grade(student) < 60;
}

std::list<Student> extract_fails4(std::list<Student>& students)
{
    std::list<Student> fails;

    std::list<Student>::iterator iter = students.begin();
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

    std::list<Student> students{student1, student2, student3, student4};
    const std::list<Student> failedStudents = extract_fails4(students);

    std::cout << "PASSED: ";
    for (std::list<Student>::const_iterator iter = students.cbegin(); iter != students.cend(); ++iter)
    {
        std::cout << '\n' << iter->name;
    }

    std::cout << "\n\nFAILED: ";
    for (std::list<Student>::const_iterator iter = failedStudents.cbegin(); iter != failedStudents.cend(); ++iter)
    {
        std::cout << '\n' << iter->name;
    }
    std::cout << std::endl;

    return 0;
}
