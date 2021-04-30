#include "Headers/string.h"
#include <iostream>

int main()
{
    mys::string str1 , str2;
    str1 = "Hello";
    str2 = ",World";
    std::cout << str1 + str2;
    
}