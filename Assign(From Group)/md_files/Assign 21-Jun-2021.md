

# Assignment No.  21-Jun-2021   
##### Himanshu Gupta CSE49   

## [Pull with Git?](https://github.com/crestfalln/LabOOP.git)  

>This assignment is best viewed on GitHub. Use above link.

## Index

1. [A Rational class, having two data members num (numerator) and den (Denominator) and default constructor, the copy constructor, and the assignment operator. Overload various arithmetic and relational operators for this class. Test it with suitable test cases.](#question-no-1)
 

---
#### Question No. 1
:   
>A Rational class, having two data members num (numerator) and den (Denominator) and default constructor, the copy constructor, and the assignment operator. Overload various arithmetic and relational operators for this class. Test it with suitable test cases.
  

#### Code
```c
//QUESTION A Rational class, having two data members num (numerator) and den (Denominator) and default constructor, the copy constructor, and the assignment operator. Overload various arithmetic and relational operators for this class. Test it with suitable test cases.
#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

class rational
{
    int m_dem,
        m_num;
    friend std::ostream& operator<<(std::ostream&, rational const&);

public:
    rational(int num = 0, int dem = 1, bool no_proc = 0)
    {
        if (dem == 0)
            throw std::logic_error("cannot divide by zero");
        if (num == 0)
        {
            dem = 1;
            no_proc = 1;
        }
        if (!no_proc)
            remove_common(num, dem);
        m_dem = dem;
        m_num = num;
    };
    rational(rational&&) = default;
    rational(rational const&) = default;
    rational& operator=(rational const&) = default;
    rational& operator=(rational&&) = default;
    int get_dem() const noexcept
    {
        return m_dem;
    }
    int get_num() const noexcept
    {
        return m_num;
    }
    rational operator+(rational const& other) const noexcept
    {
        if (other.m_num == 0)
            return *this;
        else
        {
            int cp_dem = m_dem;
            int cp_o_dem = other.m_dem;
            int hcf = remove_common(cp_dem, cp_o_dem);
            int n_dem = hcf * cp_o_dem * cp_dem;
            int n_num = (m_num * cp_o_dem + other.m_num * cp_dem) * hcf;
            return rational(n_num, n_dem);
        }
    };
    rational operator*(int const& other) const noexcept
    {
        return rational(m_num * other, m_dem);
    }
    rational operator-(rational const& other) const noexcept
    {
        return *this + other * (-1);
    };
    rational operator*(rational const& other) const noexcept
    {
        return rational(m_num * other.m_num, m_dem * other.m_dem);
    };
    rational operator/(rational const& other) const
    {
        rational cpy(other);
        cpy.reciprocal();
        return (*this)*cpy;
    };
    bool operator==(rational const& other) const noexcept
    {
        if (m_num == other.m_num && m_dem == other.m_dem)
            return true;
        else
            return false;
    }
    bool operator!=(rational const& other) const noexcept
    {
        return !(*this == other);
    }
    bool operator<(rational const& other) const noexcept
    {
        if (m_dem == other.m_dem)
            return m_num < other.m_num;
        if (m_num == other.m_num)
            return m_dem > other.m_dem;
        return m_num * other.m_dem < other.m_num * m_dem;
    }
    bool operator>(rational const& other) const noexcept
    {
        if (*this == other)
            return false;
        return !(*this < other);
    }
    bool operator<=(rational const& other) const noexcept
    {
        return !(*this > other);
    }
    bool operator>=(rational const& other) const noexcept
    {
        return !(*this < other);
    }
    operator double() noexcept
    {
        return static_cast<double>(m_num) / static_cast<double>(m_dem);
    };
    operator float() noexcept
    {
        return static_cast<float>(m_num) / static_cast<float>(m_dem);
    };
    static int remove_common(int& a, int& b) noexcept
    {
        if (a == 0 || b == 0)
            return 0;
        bool a_flag = 0;
        int hcf = 1;
        int min, max;
        if (a > b)
        {
            a_flag = 1;
            min = b;
            max = a;
        }
        else
        {
            min = a;
            max = b;
        }
        if (max % min == 0)
        {
            hcf = min;
            max /= min;
            min = 1;
        }
        else
        {
            for (int i = 2; i < static_cast<int>(sqrt(min)); i++)
            {
                while (max % i == 0 && min % i == 0)
                {
                    max /= i;
                    min /= i;
                    hcf *= i;
                }
            }
        }
        if (a_flag)
        {
            a = max;
            b = min;
        }
        else
        {
            a = min;
            b = max;
        }
        return hcf;
    };
    static int common_dem(int& a, int& b) noexcept
    {
        int hcf = remove_common(a, b);
        a = hcf * a * b;
        b = a;
        return hcf;
    }
    void reciprocal()
    {
        if(m_num == 0)
            throw std::logic_error("Cannot divide by zero! ");
        std::swap(m_num , m_dem);
    }
};
std::ostream& operator<<(std::ostream& os, rational const& rat)
{
    os << rat.m_num << '/' << rat.m_dem;
    return os;
}
std::istream& operator>>(std::istream& is, rational& rat)
{
    int a, b;
    is >> a >> b;
    rational tmp(a, b);
    std::swap(rat, tmp);
    return is;
}

int main()
{
    rational rat1, rat2;
    while (!std::cin.eof())
    {
        std::cout << "\n\nEnter rational numbers rat1 , rat2: \n";
        try
        {
            std::cin >> rat1;
            if(std::cin.eof())
                break;
            std::cin >> rat2;
        }
        catch (std::exception& e)
        {
            std::cerr << "An exception has occured while taking input! what() is: " << e.what() << std::endl;
            continue;
        }
        std::cout << "rat1 is: " << rat1 << " rat2 is: " << rat2 << "\n";
        std::cout << "rat1 + rat2: " << rat1 + rat2 << '\n'
                  << "rat1 - rat2: " << rat1 - rat2 << '\n'
                  << "rat1 x rat2: " << rat1 * rat2 << '\n';
        try
        {
            std::cout << "rat1 / rat2: " << rat1 / rat2 << '\n';
        }
        catch (std::exception& e)
        {
            std::cerr << "An exception has occured while division! what() is: " << e.what() << std::endl;
        }
        std::cout << "rat1 = rat2: " << (rat1 == rat2 ? "True" : "False") << "\n"
                  << "rat1 != rat2: " << (rat1 != rat2 ? "True" : "False") << "\n"
                  << "rat1 < rat2: " << (rat1 < rat2 ? "True" : "False") << "\n"
                  << "rat1 > rat2: " << (rat1 > rat2 ? "True" : "False") << "\n"
                  << "rat1 <= rat2: " << (rat1 <= rat2 ? "True" : "False") << "\n"
                  << "rat1 >= rat2: " << (rat1 >= rat2 ? "True" : "False") << "\n"
                  << "rat1 val in double: " << static_cast<double>(rat1) << "\n"
                  << "rat1 val in float: " << static_cast<float>(rat1) << "\n"
                  << "rat2 val in double: " << static_cast<double>(rat2) << "\n"
                  << "rat2 val in float: " << static_cast<float>(rat2) << "\n"
                  << std::endl;
    }
    return 0;
} 
```

#### $ Assign 21-Jun-2021/bin/1.o     

-

**Input**  
12 11                      
23 12                      
11 11                      
11 11                      
0 0                      
23 0                      
13 20                      
12 20                      
12 21                      
0 23                      
12 32  
12 32   

**Output**  
  
  
Enter rational numbers rat1 , rat2:   
rat1 is: 12/11 rat2 is: 23/12  
rat1 + rat2: 397/132  
rat1 - rat2: -109/132  
rat1 x rat2: 23/11  
rat1 / rat2: 144/253  
rat1 = rat2: False  
rat1 != rat2: True  
rat1 < rat2: True  
rat1 > rat2: False  
rat1 <= rat2: True  
rat1 >= rat2: False  
rat1 val in double: 1.09091  
rat1 val in float: 1.09091  
rat2 val in double: 1.91667  
rat2 val in float: 1.91667  
  
  
  
Enter rational numbers rat1 , rat2:   
rat1 is: 1/1 rat2 is: 1/1  
rat1 + rat2: 2/1  
rat1 - rat2: 0/1  
rat1 x rat2: 1/1  
rat1 / rat2: 1/1  
rat1 = rat2: True  
rat1 != rat2: False  
rat1 < rat2: False  
rat1 > rat2: False  
rat1 <= rat2: True  
rat1 >= rat2: True  
rat1 val in double: 1  
rat1 val in float: 1  
rat2 val in double: 1  
rat2 val in float: 1  
  
  
  
Enter rational numbers rat1 , rat2:   
An exception has occured while taking input! what() is: cannot divide by zero  
  
  
Enter rational numbers rat1 , rat2:   
An exception has occured while taking input! what() is: cannot divide by zero  
  
  
Enter rational numbers rat1 , rat2:   
rat1 is: 13/20 rat2 is: 3/5  
rat1 + rat2: 125/20  
rat1 - rat2: 1/4  
rat1 x rat2: 39/100  
rat1 / rat2: 13/12  
rat1 = rat2: False  
rat1 != rat2: True  
rat1 < rat2: False  
rat1 > rat2: True  
rat1 <= rat2: False  
rat1 >= rat2: True  
rat1 val in double: 0.65  
rat1 val in float: 0.65  
rat2 val in double: 0.6  
rat2 val in float: 0.6  
  
  
  
Enter rational numbers rat1 , rat2:   
rat1 is: 12/21 rat2 is: 0/1  
rat1 + rat2: 12/21  
rat1 - rat2: 12/21  
rat1 x rat2: 0/1  
rat1 / rat2: An exception has occured while division! what() is: Cannot divide by zero!   
rat1 = rat2: False  
rat1 != rat2: True  
rat1 < rat2: False  
rat1 > rat2: True  
rat1 <= rat2: False  
rat1 >= rat2: True  
rat1 val in double: 0.571429  
rat1 val in float: 0.571429  
rat2 val in double: 0  
rat2 val in float: 0  
  
  
  
Enter rational numbers rat1 , rat2:   
rat1 is: 3/8 rat2 is: 3/8  
rat1 + rat2: 6/1  
rat1 - rat2: 0/1  
rat1 x rat2: 9/64  
rat1 / rat2: 1/1  
rat1 = rat2: True  
rat1 != rat2: False  
rat1 < rat2: False  
rat1 > rat2: False  
rat1 <= rat2: True  
rat1 >= rat2: True  
rat1 val in double: 0.375  
rat1 val in float: 0.375  
rat2 val in double: 0.375  
rat2 val in float: 0.375  
  
 

---


