// Exercise 3.6
// The average-grade computation in §3.1/36 might divide by zero if the student didn't enter any grades.
// Division by zero is undefined in C++, which means that the implementation is permitted to do anything it likes.
// What does your C++ implementation do in this case? Rewrite the program so that its behavior does not depend on
// how the implementation treats division by zero.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

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

    int count = 0;
    double sum = 0.0;

    double homeworkGrade;
    while (std::cin >> homeworkGrade)
    {
        sum += homeworkGrade;
        ++count;
    }

    const double homework = (count == 0) ? 0 : (0.4 * sum / count);

    std::streamsize prec = std::cout.precision();
    std::cout << std::endl << "Your final grade is " << std::setprecision(3)
              << 0.2 * midterm + 0.4 * final + homework
              << std::setprecision(prec) << std::endl;

    return 0;
}
