#include <iostream>
#include <memory>
#include <cstring>

namespace mys
{
    // Definations
    template <typename T> class Vector;
    template <typename T> class VectorIterator;
    //


    template <typename T>
    class Vector
    {
    public:
        using iterator = VectorIterator<T>;
        using m_type = T;
        using p_type = T*;
    
    private:
        m_type * data = nullptr;
        size_t a_size = 10;
        size_t m_size = 0;
        std::allocator<m_type> alloc;

    public:
        Vector(int a = 2)
        {
            a_size = a;
            data = alloc.allocate(a_size);
        }
        inline iterator begin()
        {
            return data;
        };

        inline iterator end()
        {
            return data + m_size; 
        };

        void extend(int fac = 1)
        {
            size_t new_a_size = a_size << fac;
            m_type* new_data = alloc.allocate(new_a_size);
            for(int i = 0 ; i < m_size; i++)
                *(new_data + i) = *(data + i);
            alloc.deallocate(data , a_size);
            data = new_data;
            a_size = new_a_size;
        };

        void shrink(int fac = 1)
        {
            if((a_size << fac) > m_size)
            {
                void * dummys = begin() + (a_size << fac);
                void * dummye = begin() + (a_size);
                alloc.deallocate(dummys,  (char)dummye - (char)dummys);
            }
        };

        void insert(m_type const & el)
        {
            if(m_size >= a_size)
                extend();
            *end() = el;
            m_size++;
        };

        void remove()
        {
            shrink();
            m_size--;
        };
        
        ~Vector()
        {
            alloc.deallocate(begin() , a_size);
        }
    };


    template <typename T>
    class VectorIterator
    {
    public:
        using m_type = T;
        using p_type = T*;

    private:
        p_type pointer = nullptr;

    public:
        VectorIterator(){};
        VectorIterator(p_type const & p){ pointer = p; }
        VectorIterator operator=(p_type const & p)
        {
            pointer = p;
            return *this;
        };

        VectorIterator operator=(VectorIterator const & it)
        {
            pointer = it.pointer;
            return *this;
        };

        VectorIterator operator++()
        { 
            pointer++;
            return *this;
        };

        VectorIterator operator++(int)
        {
            VectorIterator dum = *this;
            dum++;
            return dum;
        };

        VectorIterator operator--()
        { 
            pointer--;
            return *this;
        };

        VectorIterator operator--(int)
        {
            VectorIterator dum = *this;
            dum--;
            return dum;
        };

        VectorIterator operator+(int a) const 
        {
            VectorIterator dum = *this;
            dum.pointer += a;
            return dum;
        };

        VectorIterator operator-(int a) const 
        {
            VectorIterator dum = *this;
            dum.pointer -= a;
            return dum;
        };

        operator p_type() const
        {
            return pointer;
        }

        m_type& operator*(){ return *pointer; };
    };
}