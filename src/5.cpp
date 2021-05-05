#include "Headers/vector.h"


int main()
{
    mys::Vector<int> vec;
    vec.insert(23);
    vec.insert(10);
    vec.insert(12);
    for(auto it : vec)
    {
        std::cout << it << ' ';
    }
}