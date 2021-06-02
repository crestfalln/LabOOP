//QUESTION Write and run a program that directly implements the quotient operator / and the remainder operator % for the division of positive integers.

#include <iostream>
#include <utility>

struct DivQues : public std::pair<int, int> //inheritied class DivQues for storage of divident and divisor
{
    using std::pair<int , int>::pair; //inheriting constructor from std::pair
};
std::ostream &operator<<(std::ostream &os, DivQues const &l_div_result) //ostream insertion overload for DivQues, prints in a pretty format.
{
    os << "Divident: " << l_div_result.first << '\t'
       << "Divisor: " << l_div_result.second;
    return os;
}
std::istream &operator>>(std::istream &is, DivQues &divis) //istream extraction overload for DivQues, puts 2 ints in DivQues
{
    std::string dividend, divisor;
    is >> dividend;
    if(is.eof())    //checks for eof after every extraction
        return is;
    is >> divisor;
    if(is.eof())
        return is;
    DivQues divisTemp({std::stoi(dividend), std::stoi(divisor)}); //exception safety, if throws divis is still valid and we are rid of bad input
    divis = std::move(divisTemp);
    return is;
}

struct DivAns : public std::pair<int, int> //inherited class DivAns for storage of quotient and remainder
{
    using std::pair<int , int>::pair; 
};
std::ostream &operator<<(std::ostream &os, DivAns const &l_div_result)
{
    os << "Quotient: " << l_div_result.first << '\t'
       << "Remainder: " << l_div_result.second;
    return os;
}

DivAns l_div(DivQues const &divis) //division function
{
    if (divis.second == 0)
        throw std::runtime_error("division by zero not possible");
    DivAns result;
    result.first = divis.first / divis.second;
    result.second = divis.first % divis.second;
    return result;
}

int main()
{
    std::cout << "Keyboard Interupt to Exit" << std::endl;
    while (true)
    {
        DivQues divis;

        try
        {
            std::cin >> divis;
        }
        catch (const std::out_of_range &e)  //Detects out of range input
        {
            std::cerr << "Integer Boundary Error: out_of_range" << '\n';
            std::cout << std::endl;
            continue;
        }
        catch (const std::invalid_argument &e) //Detects invalid input
        {
            std::cerr << "Invalid Argument" << '\n';
            std::cout << std::endl;
            continue;
        }

        if(std::cin.eof()) //Breaks if EOF reached
            break;

        std::cout << divis << std::endl;

        try
        {
            std::cout << l_div(divis) << '\n';
        }

        catch (const std::runtime_error &e) //Detects if dividing by zero
        {
            std::cerr << "Exception Caught: " << e.what() << '\n';
        }
        std::cout << std::endl;

    }
}
