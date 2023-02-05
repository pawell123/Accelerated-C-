// Exercise 4.8
// If the following code is legal, what can we infer about the return type of f?
// double d = f()[n];


int main()
{
    /*****
    double d = f()[n];
    *****/

    // f() returns type that implements operator[] that returns type T. T is double or can be converted to double (for example std::vector<double>)

    return 0;
}
