#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;

    std::cout << "Hello " << name << "!" << std::endl;

    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    std::cin >> midterm >> final;

    std::cout << "Enter all your homework grades, followed by end-of-file: ";

    std::vector<double> homeworkGrades;
    double homeworkGrade;
    while (std::cin >> homeworkGrade)
    {
        homeworkGrades.push_back(homeworkGrade);
    }

    if (homeworkGrades.empty())
    {
        std::cout << std::endl << "You must enter your grades. Please try again" << std::endl;
        return 1;
    }

    std::sort(homeworkGrades.begin(), homeworkGrades.end());

    std::vector<double>::size_type size = homeworkGrades.size();

    std::vector<double>::size_type mid = size/2;
    double median = size % 2 == 0 ? (homeworkGrades[mid] + homeworkGrades[mid-1]) / 2
                                  : homeworkGrades[mid];

    std::streamsize prec = std::cout.precision();
    std::cout << "Your final grade is " << std::setprecision(3)
              << 0.2 * midterm + 0.4 * final + 0.4 * median
              << std::setprecision(prec) << std::endl;

    return 0;
}
