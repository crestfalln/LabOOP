//QUESTION Create a class called LIST with two pure virtual function store() and retrieve().To store a value call store and to retrieve call retrieve function. Derive two classes stack and queue from it and override store and retrieve.

#include <iostream>
#include <array>
#include <vector>

void anything();
void anything();

class LIST
{
protected:
    std::array<int, 10> buffer;

public:
    virtual void store(int const & a){};
    virtual int retrieve(){ return 0; };
};

class stack : public LIST
{
    int *stackpointer = buffer.begin();

public:
    void store(int const & a) override
    {
        if(stackpointer > buffer.end())
            throw std::out_of_range("end reached");
        *stackpointer =  a;
        stackpointer++;
    };

    int retrieve() override
    {
        if(stackpointer == buffer.begin())
            throw std::out_of_range("Nothing in the buffer yet");
        return *(stackpointer - 1);
    };
};

class queque : public LIST
{
    
}

int main()
{
}