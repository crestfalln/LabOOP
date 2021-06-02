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