#include "analysis.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include "grade.hpp"
#include "median.hpp"
#include "Student.hpp"

namespace
{
double gradeAux(const Student& student)
{
    try
    {
        return grade(student);
    }
    catch (const std::domain_error&)
    {
        return grade(student.midterm, student.final, 0.0);
    }
}

double average(const std::vector<double>& vec)
{
    return std::accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();
}

double averageGrade(const Student& student)
{
    return grade(student.midterm, student.final, average(student.homeworks));
}

double optimisticMedian(const Student& student)
{
    std::vector<double> nonZero;
    std::remove_copy(student.homeworks.cbegin(), student.homeworks.cend(), std::back_inserter(nonZero), 0);

    if (nonZero.empty())
    {
        return grade(student.midterm, student.final, 0.0);
    }
    return grade(student.midterm, student.final, nonZero);
}
}

double medianAnalysis(const std::vector<Student>& students)
{
    std::vector<double> grades;
    std::transform(students.cbegin(), students.cend(), std::back_inserter(grades), gradeAux);
    return median(grades);
}

double averageAnalysis(const std::vector<Student>& students)
{
    std::vector<double> grades;
    std::transform(students.cbegin(), students.cend(), std::back_inserter(grades), averageGrade);
    return median(grades);
}


double optimisticMedianAnalysis(const std::vector<Student>& students)
{
    std::vector<double> grades;
    std::transform(students.cbegin(), students.cend(), std::back_inserter(grades), optimisticMedian);
    return median(grades);
}

void writeAnalysis(std::ostream& out,
                   const std::string& name,
                   double analysis(const std::vector<Student>&),
                   const std::vector<Student>& studentsWithAllHomeworks,
                   const std::vector<Student>& studentsWithoutAllHomeworks)
{
    out << "Analysis " << name << ":" << std::endl;
    out << "Median of grades for students with all homeworks : " << analysis(studentsWithAllHomeworks) << std::endl;
    out << "Median of grades for students without all homeworks : " << analysis(studentsWithoutAllHomeworks) << std::endl;
}
