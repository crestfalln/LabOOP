#include "Headers/string.h"
#include <iostream>
#include <string.h>

int main()
{
    mys::string str1 , str2;
    char sr1[] = "Hello"; 
    char sr2[] = "world";
    str1 = "Hello";
    str2 = ",World";
    std::cout << str1 + str2 << std::endl;
    str1 = str2;
    std::cout << str1 << std::endl ;
    std::cout << "String Size: " << str1.size() << '\n'; 
    std::cout << "Lower Case: " << str1.to_lower() << "\nUpper Case: " << str1.to_upper() << std::endl;
}