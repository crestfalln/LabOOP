#include <memory>

namespace mys
{
    template <typename T = char>
    class MyString
    {
    public:
        // Types
        size_t M_size = 0;
        size_t A_size = 100;
        T *str = NULL;
        std::allocator<T> alloc;

        // Constructors
        MyString(size_t const default_A_size = 100);
        MyString(MyString const &);
        MyString(std::string const &);
        MyString(char const[]);

        // Destructor
        ~MyString(void);

        // Members
        size_t size();
        MyString &resize(size_t const size);
        MyString &extend();
        MyString &operator+(MyString &) const;
        MyString &operator=(MyString);
        MyString &operator=(char const[]);
        bool operator<=(MyString &) const;
        void to_upper();
        void to_lower();

        // Friends
        template <typename U>
        friend void swap(MyString<U> &, MyString<U> &);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &, MyString<U> &);
    };

    //MyString Definations

    //Constructors

    template <typename T>
    MyString<T>::MyString(size_t const default_A_size)
    {
        A_size = default_A_size;
        str = alloc.allocate(A_size);
    }

    template <typename T>
    MyString<T>::MyString(MyString const &string)
    {
        str = alloc.allocate(string.A_size);
        M_size = string.M_size;
        for (int it = 0; it < M_size; it++)
        {
            *(str + it) = *(string.str + it);
        }
    }

    template <typename T>
    MyString<T>::MyString(char const string[])
    {
        str = alloc.allocate(A_size);
        for (int it = 0; string[it] != '\0'; it++)
        {
            if (it > A_size)
                extend();
            *(str + it) = string[it];
            M_size++;
        }
    }

    //Members

    template <typename T>
    MyString<T> &MyString<T>::operator=(MyString<T> string)
    {
        swap(*this, string);
        return *this;
    }

    template <typename T>
    MyString<T> &MyString<T>::operator=(char const string[])
    {
        MyString<T> dummy(string);
        swap(*this, dummy);
        return *this;
    }

    template <typename T>
    MyString<T> &MyString<T>::extend()
    {
        MyString dummy(*this);
        alloc.deallocate(str, A_size);
        str = alloc.allocate(A_size < 1);
        A_size = A_size << 1;
        for (int it = 0; it < dummy.M_size; it++)
            *(str + it) = *(dummy.str + it);
        return *this;
    }

    // Destructor
    template <typename T>
    MyString<T>::~MyString()
    {
        alloc.deallocate(str, A_size);
    }

    // Friends
    template <typename T>
    void swap(MyString<T> &string1, MyString<T> &string2)
    {
        using std::swap;
        swap(string1.alloc, string2.alloc);
        swap(string1.A_size, string2.A_size);
        swap(string1.M_size, string2.M_size);
        swap(string1.str, string2.str);
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &os, MyString<T> &string)
    {
        for (int it = 0; it < string.M_size; it++)
            os << *(string.str + it);
        return os;
    }

    // Useful Alias
    typedef MyString<char> string;
}