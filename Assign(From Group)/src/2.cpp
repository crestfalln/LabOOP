//QUESTION Write a function that creates a vector of user given size M using new operator.

#include <iostream>
#include <vector>

int main()
{
    int M;
    std::cout << "Enter the size of the vector you want to create: ";
    std::cin >> M;
    auto vec = new std::vector<int>(M , 0);
    std::cout << "The size of the vector is: " << vec->size() << '\n';
    std::cout << "The Elements of the vector are: " << '\n';
    for(auto it : *vec)
        std::cout << it << '\n';
    return 0;
}