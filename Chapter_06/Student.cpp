#include "Student.hpp"
#include <iostream>

bool compare(const Student& lhs, const Student& rhs)
{
    return lhs.name < rhs.name;
}

std::istream& read(std::istream& in, Student& student)
{
    in >> student.name >> student.midterm >> student.final;
    readHomeworks(in, student.homeworks);
    return in;
}

std::istream& readHomeworks(std::istream& in, std::vector<double>& homeworks)
{
    if (in)
    {
        homeworks.clear();

        double homework;
        while (in >> homework)
        {
            homeworks.push_back(homework);
        }
        in.clear();
    }
    return in;
}
