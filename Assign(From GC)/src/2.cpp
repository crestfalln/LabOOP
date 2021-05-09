//QUESTION Write a program to find the greatest of two given numbers in two different classes using friend function.

#include <iostream>
#include <utility>

class Z
{
public:
    double real, imag;
    Z operator+(const Z &b) const
    {
        Z result;
        result.real = real + b.real;
        result.imag = imag + b.imag;
        return result;
    }
    std::ostream &operator<<(std::ostream &os) const
    {
        os << this->real << " + (" << this->imag << "i)";
        return os;
    }
    Z(){};
    Z(double);
    Z(double, double);
};
std::ostream &operator<<(std::ostream &os , const Z z)
{
    os << z.real << " + (" << z.imag << "i)";
    return os;
}

Z::Z(double a)
{
    imag = a;
    real = a;
}

Z::Z(double r, double i)
{
    real = r;
    imag = i;
}

int main()
{
    //No initialization constructor
    Z nI1, nI2;
    //Same init constructor
    Z sI1(3.14), sI2(2.23);
    //Diff init constructor;
    Z dI1(3.14, 1.0), dI2(2.23, 2.0);

    //Printing additions
    std::cout << nI1 + nI2 << '\n';
    std::cout << sI1 + sI2 << '\n';
    std::cout << dI2 + dI1 << '\n';
}
