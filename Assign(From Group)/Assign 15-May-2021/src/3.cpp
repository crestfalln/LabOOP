//QUESTION Write a program to evaluate the following investment equation
//V = P(1+r)n
//and print the tables which would give the value of V for various
//of the following values of P, r and n:
//P: 1000, 2000, 3000,……………,10,000
//r: 0.10, 0.11, 0.12,………………….,0.20
//n: 1, 2, 3,…………………………………..,10

#include <iostream>

int main()
{
    std::cout << "|P    "
              << "|r    "
              << "|n    "
              << "|V|" << std::endl;
    std::cout << "|---|---|---|---|" << std::endl;
    for (int n = 1; n <= 10; n++)
    {
        for (int r = 10; r <= 20; r++) // Don't work with doubles use ints and then divide by 10 later.
        {
            for (int P = 10; P <= 100; P += 10)
            {
                long V = P * (100 + r) * n;
                std::cout << '|' << P*10 << "    |" << r/double(100) << "    |" << n << "    |" << V << '|' << "\n";
            }
        }
    }
}