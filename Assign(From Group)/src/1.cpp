//QUESTION Write a function using reference variables as arguments to swap the values of a pair of integers.

#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    std::cout << "Enter two Numbers: " << "\n"; 
    int a, b;
    std::cin >> a >> b;
    std::cout << "Before Swapping: " << "\n" << "a: " << a << "\n" << "b: " << b << "\n";
    swap(a , b);
    std::cout << "After Swapping: " << "\n" << "a: " << a << "\n" << "b: " << b << "\n";
    return 0;
}