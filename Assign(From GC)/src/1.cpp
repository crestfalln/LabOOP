//QUESTION Write a program for multiplication of two matrices using OOP.

#include <iostream>
#include <utility>
#include <typeinfo>

template <typename T>
class matrix
{
protected:
    int rows = 1, columns = 1;

public:
    T *grid = new T[rows * columns];
    inline T &operator[](std::pair<int, int> pos) const { return grid[(pos.first * columns) + pos.second]; }
    template <typename F>
    friend std::ostream &operator<<(std::ostream &os, const matrix<F> &mat);
    template <typename F>
    friend std::istream &operator>>(std::istream &is, matrix<F> &mat);
    matrix operator*(matrix &);
    matrix(int a = 1, int b = 1)
    {
        rows = a;
        columns = b;
    }
};

template <typename T>
matrix<T> matrix<T>::operator*(matrix<T> &b)
{
    std::invalid_argument inv("matrix multiplication impossible, check input.");
    if (columns != b.rows)
        throw inv;
    else
    {
        matrix<T> result(rows, b.columns);
        for (int it1 = 0; it1 < rows; it1++)
        {
            for (int it2 = 0; it2 < b.columns; it2++)
            {
                result[{it1, it2}] = 0;
                for (int it3 = 0; it3 < rows; it3++)
                {
                    result[{it1, it2}] += operator[]({it1, it3}) * b[{it3, it2}];
                }
            }
        }
        return result;
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &mat)
{
    for (int it1 = 0; it1 < mat.rows; it1++)
    {
        for (int it2 = 0; it2 < mat.columns; it2++)
        {
            os << mat[{it1, it2}] << ' ';
        }
        os << '\n';
    }
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, matrix<T> &mat)
{
    is >> mat.rows >> mat.columns;
    for (int it1 = 0; it1 < mat.rows; it1++)
    {
        for (int it2 = 0; it2 < mat.columns; it2++)
        {
            is >> mat[{it1, it2}];
        }
    }
    return is;
}

int main()
{
    matrix<float> matrx1, matrx2;
    std::cout << "Enter the matrix 1(First number of rows and columns and then the elements:\n";
    std::cin >> matrx1;
    std::cout << "Enter the matrix 1(First number of rows and columns and then the elements:\n";
    std::cin >> matrx2;
    std::cout << "\nMultiplication is: \n" << matrx1*matrx2;
}
