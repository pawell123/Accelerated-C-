#pragma once
#include <iosfwd>
#include <string>
#include <vector>

struct Student;

double medianAnalysis(const std::vector<Student>&);

double averageAnalysis(const std::vector<Student>&);

double optimisticMedianAnalysis(const std::vector<Student>&);

void writeAnalysis(std::ostream&, const std::string& name, double analysis(const std::vector<Student>&),
                   const std::vector<Student>& studentsWithAllHomeworks, const std::vector<Student>& studentsWithoutAllHomeworks);
