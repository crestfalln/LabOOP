#include <iostream>
#include "Headers/matrix.h"

int main()
{
    matrix<int> matrx1, matrx2;
    std::cout << "Enter the matrix 1(First number of rows and columns and then the elements:\n";
    std::cin >> matrx1;
    std::cout << "Enter the matrix 1(First number of rows and columns and then the elements:\n";
    std::cin >> matrx2;
    std::cout << "\nMultiplication is: \n" << matrx1*matrx2;
}
