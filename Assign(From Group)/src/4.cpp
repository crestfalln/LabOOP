//QUESTION An election is contested by five candidates. The candidates are numbered 1 to 5 and the voting is done by marking the candidate number on the ballot paper. Write a program to read the ballots and count the vote cast for each candidate using an array variable count. In case, a number read is outside the range 1 to 5, the ballot should be considered as a “spoilt ballot” and the program should also count the numbers of “spoilt ballots”.

#include <iostream>
#include <array>

int main()
{
    std::array<int , 5> count;
    int spoiltVotes;
    for(int i; std::cin >> i; )
    {
        if(i > 5 || i < 1)
            spoiltVotes++;
        else
            count[i-1]++;
    }
    std::cout << "No of Votes: " << std::endl;
    std::cout << "|Candidate|Ballot Count|" << std::endl;
    std::cout << "|---|---|" << std::endl;
    for(int it = 0; it < count.size(); it++)
    {
        std::cout << "|" <<  it+1 << "|   " << count[it] << "|\n";
    } 
    std::cout << "Total No. of spoilt votes: " << spoiltVotes;
}