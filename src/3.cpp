#include <iostream>

class num
{
    int number;

public:
    num(int x) { number = x; }
    friend num add(const num &, const num &);
    friend std::ostream& operator<<(std::ostream &os , const num& a);
};
std::ostream& operator<<(std::ostream &os , const num& a)
{
    os << a.number;
    return os;
}

num add(const num &a, const num &b)
{
    return num(a.number + b.number);
}

int main()
{
    num a(1) , b(2);
    std::cout << add(a , b);
}