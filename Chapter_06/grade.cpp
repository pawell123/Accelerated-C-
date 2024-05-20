#include "grade.hpp"
#include <stdexcept>
#include "Student.hpp"
#include "median.hpp"

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& homeworks)
{
    if (homeworks.empty())
    {
        throw std::domain_error("Student has not done any homework!");
    }
    return grade(midterm, final, median(homeworks));
}

double grade(const Student& student)
{
    return grade(student.midterm, student.final, student.homeworks);
}
