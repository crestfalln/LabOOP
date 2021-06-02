

# Assignment No.  25-May-2021   
##### Himanshu Gupta CSE49   

## [Pull with Git?](https://github.com/crestfalln/LabOOP.git)  

>This assignment is best viewed on GitHub. Use above link.

## Index

1. [Write and run a program that directly implements the quotient operator / and the remainder operator % for the division of positive integers.](#question-no-1)
2. [Write a function which evaluates the third degree polynomial a0 + a1x + a2x2 + a3x3. Also implement this function using Horner’s Algorithm, grouping the calculations as a0 + (al + (a2 + a3x)x)x . Compare the efficiency of both the functions.](#question-no-2)
    * [A Note on Time Complexity](#a-note-about-time-complexity) 

---
#### Question No. 1  
:   
>Write and run a program that directly implements the quotient operator / and the remainder operator % for the division of positive integers.
  

#### Code
```c
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
 
```

#### $ Assign 25-May-2021/bin/1.o     

-

**Input**  
123 32          
234 0          
21 7          
1223453145141234 323          
12 3          
23            

**Output**  
Keyboard Interupt to Exit  
Divident: 123	Divisor: 32  
Quotient: 3	Remainder: 27  
  
Divident: 234	Divisor: 0  
Exception Caught: division by zero not possible  
  
Divident: 21	Divisor: 7  
Quotient: 3	Remainder: 0  
  
Integer Boundary Error: out_of_range  
  
Divident: 12	Divisor: 3  
Quotient: 4	Remainder: 0  
  
 

---


#### Question No. 2  
:   
>Write a function which evaluates the third degree polynomial a0 + a1x + a2x2 + a3x3. Also implement this function using Horner’s Algorithm, grouping the calculations as a0 + (al + (a2 + a3x)x)x . Compare the efficiency of both the functions.
  

#### Code
```c
//QUESTION Write a function which evaluates the third degree polynomial a0 + a1x + a2x2 + a3x3. Also implement this function using Horner’s Algorithm, grouping the calculations as a0 + (al + (a2 + a3x)x)x . Compare the efficiency of both the functions.

long horner_impl_poly_three(long x , long a0 = 1 , long a1 = 2, long a2 = 43, long a3 = 3)
{
    /* Average time (cacluating 100 billion instances with x from 0 ... 100billion) from 1000 runs using GNU time and GNU parralel
     * took net 4min 21secs to run 1000 jobs in parallel on a 8 core processor with SMT clocked at 4.0ghz
     * real 4.14
     * user 4.04
     * sys 0.00/0.004
    */ 
    return a0 + (a1 + (a2 + a3*x)*x)*x;
}

long poly_three(long x , long a0 = 1, long a1 = 2, long a2 = 43, long a3 = 3)
{
    /* Average time (cacluating 100 billion instances with x from 0 ... 100billion) from 1000 runs using GNU time and GNU parralel
     * took net 4min 54secs to run 1000 jobs in parallel on a 8 core processor with SMT clocked at 4.0ghz
     * real 4.67
     * user 4.58
     * sys 0.00/0.004
    */
    return a0 + a1*x + a2*x*x + a3*x*x*x;
}

int main()
{
    for(long x = 0 ; x < 1000000000; x++)
    {
        poly_three(x , 1 , 2 , 43 , 3);
    }
    /*
    for(long x = 0 ; x < 1000000000; x++)
    {
        horner_impl_poly_three(x , 1 , 2 , 43 , 3);
    }
    */
} 
```

#### $ Assign 25-May-2021/bin/2.o     

-

**Input**  
 

**Output**  
 

## A note about time complexity:

```
It seems that time complexity of both algorithms are of O(1). This was verified using various
inputs of 'a' and 'x' which more or less ran in the same time. Along with that it also seems 
that Horner's algorithm is a little bit faster. This may be due to less multiplication calls 
in Horner's (3 compared to 6). But modern x86-64 processors are really fast at 64-bit int 
multiplication, so the change only becomes apparent when the iteration count goes into the range
of tens of billions. It is also of note that the method used for calculating the average time was
multithreaded and was done with a used computer which could render the results, hence the average 
erroneous. The sample of 1000 is also not that big.
```

---


