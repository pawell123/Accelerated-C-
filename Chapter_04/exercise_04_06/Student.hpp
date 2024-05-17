#ifndef GUARD_STUDENT_HPP
#define GUARD_STUDENT_HPP

#include <iosfwd>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    double finalGrade;
};

bool compare(const Student&, const Student&);
std::istream& readHomeworks(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student&);

#endif
