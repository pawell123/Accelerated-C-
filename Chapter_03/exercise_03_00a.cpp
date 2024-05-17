// Exercise 3.0a
// Compile, execute, and test the programs in this chapter.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;

    std::cout << "Hello " << name << '!' << std::endl;

    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    std::cin >> midterm >> final;

    std::cout << "Enter all your homework grades, followed by end-of-file: ";

    int count = 0;
    double sum = 0.0;

    double homeworkGrade;
    while (std::cin >> homeworkGrade)
    {
        sum += homeworkGrade;
        ++count;
    }

    const std::streamsize prec = std::cout.precision();
    std::cout << "Your final grade is " << std::setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
              << std::setprecision(prec) << std::endl;

    return 0;
}
