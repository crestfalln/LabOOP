//QUESTION Write a program to evaluate the following function to 0.0001% accuracy
/*
 *(a) sin x = x – x3/3! + x5/5! – x7/7! +…………
 *(b) SUM = 1+ (1/2)2 + (1/3)3 + (1/4)4 + ………
 *(c) Cos x = 1 –x2/2! + x4/4! – x6/6! + ………
*/

#include <iostream>
#include <cmath>

namespace mine
{
    long factorial(int n)
    {
        if (n <= 1)
            return 1;
        return n * factorial(n - 1);
    }

    double sin(double angle, int stage = 0)
    {
        double el = (pow(-1, stage) * pow(angle, 2 * stage + 1)) / factorial(2 * stage + 1);
        if (fabs(el) <= 0.000001 && stage != 0)
            return 0;
        return el + sin(angle, stage + 1);
    }
    double cos(double angle, int stage = 0)
    {
        double el = (pow(-1, stage) * pow(angle, 2 * stage)) / factorial(2 * stage);
        if (fabs(el) <= 0.000001 && stage != 0)
            return 0;
        return el + cos(angle, stage + 1);
    }
    constexpr inline double sum(int stage = 1)
    {
        double el = pow(1 / stage, stage);
        if (fabs(el) <= 0.000001)
            return 0;
        return el + sum(stage + 1);
    }
}

int main()
{
    double angleFsin = 3, angleFcos = 2;
    std::cout << "Enter angle for sin and then cosine to calculate: \n";
    std::cin >> angleFsin >> angleFcos;
    std::cout << "Sin: " << mine::sin(angleFsin) << std::endl
              << "Cos: " << mine::cos(angleFcos) << std::endl
              << "The sum that does not take a argument: " << mine::sum();
    return 0;
}