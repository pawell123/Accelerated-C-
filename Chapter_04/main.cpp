#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include "grade.hpp"
#include "Student.hpp"

// Exercise 4.0 (Example)

void exercise_4_0()
{
    std::vector<Student> students;

    Student student;
    std::string::size_type nameMaxLength = 0;
    while (read(std::cin, student))
    {
        nameMaxLength = std::max(nameMaxLength, student.name.size());
        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), compare);

    std::cout << std::endl;
    for (const auto& student: students)
    {
        std::cout << student.name << std::string(nameMaxLength - student.name.size() + 1, ' ');

        try
        {
            const double studentGrade = grade(student);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << grade(student) << std::setprecision(prec);

        } catch (const std::domain_error& error)
        {
            std::cout << error.what();
        }
        std::cout << std::endl;
    }
}


// Exercise 4.1

void exercise_4_1()
{
    /*****
    int maxlen;
    Student s;
    std::max(s.name.size(), maxlen);
    ******/
    // Above code is not correct (cannot deduce return type)

    std::string::size_type maxlen = 0;
    Student s;
    std::max(s.name.size(), maxlen);
}

// Exercise 4.2

void exercise_4_2()
{
    for (int i = 0; i != 101; ++i)
    {
        std::cout << std::setw(5) << i << " " << std::setw(5) <<i*i << std::endl;
    }
}


// Exercise 4.3

void exercise_4_3()
{
    const int range = 1000;
    const auto maxValue1 = static_cast<int>(std::to_string(range-1).size());
    const auto maxValue2 = static_cast<int>(std::to_string((range-1)*(range-1)).size());

    for (int i = 0; i != range; ++i)
    {
        std::cout << std::setw(maxValue1) << i << " " << std::setw(maxValue2) <<i*i << std::endl;
    }
}


// Exercise 4.4

void exercise_4_4()
{
    const double range = 1000;
    const auto maxValue1 = static_cast<int>(std::to_string(range-1).size());
    const auto maxValue2 = static_cast<int>(std::to_string((range-1)*(range-1)).size());

    for (double i = 0.0; i != range; ++i)
    {
        std::cout << std::fixed << std::setw(maxValue1) << i << " " << std::setw(maxValue2) << i*i << std::endl;
    }
}


// Exercise 4.5

std::vector<std::string> readWords(std::istream& in)
{
    std::vector<std::string> ret;
    std::string word;
    while (in >> word)
    {
        ret.push_back(word);
    }
    return ret;
}

void exercise_4_5a()
{
    std::vector<std::string> words = readWords(std::cin);

    std::cout << "Number of words: " << words.size() << std::endl;
}

void exercise_4_5b()
{
    std::vector<std::string> words = readWords(std::cin);

    std::sort(words.begin(), words.end());

    std::string previousWord;
    std::string::size_type counter = 0;

    for (std::string::size_type i = 0; i != words.size(); ++i)
    {
        const auto& currentWord = words[i];

        if (i == 0 || currentWord == previousWord) {
            ++counter;
        } else {
            std::cout << "Word: " << previousWord << ": " << counter << std::endl;

            counter = 1;
        }

        if (i == words.size() - 1) {
            std::cout << "Word: " << currentWord << ": " << counter << std::endl;
            return;
        }
        previousWord = currentWord;
    }
}

// Exercise 4.6

// Exercise 4.7

void exercise_4_7()
{
    std::vector<double> vec = { 1.0, 2.0, 3.0 };

    std::cout << "Average: " << std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size() << std::endl;

    // or

    double sum = 0.0;
    for (auto elem : vec)
    {
        sum += elem;
    }

    std::cout << "Average: " << sum / vec.size() << std::endl;
}


// Exercise 4.8

void exercise_4_8()
{
    /*****
    double d = f()[n];
    *****/

    // f() returns type that supports operator[] that returns T. T is double or can be converted to double (fox example std::vector<double>)
}

int main()
{
    //exercise_4_0();
    //exercise_4_1();
    //exercise_4_3();
    exercise_4_4();
    //exercise_4_7();

}
