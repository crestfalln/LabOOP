#include <memory>

namespace mys
{
    template <typename T = char>
    class MyString
    {
        // Types
        size_t M_size = 0;
        size_t A_size = 100;
        T *str = NULL;
        std::allocator<T> alloc;

    public:
        // Constructors
        MyString(size_t const default_A_size = 100);
        MyString(MyString const &);
        MyString(std::string const &);
        MyString(char const[]);

        // Destructor
        ~MyString(void);

        // Members
        MyString &extend(size_t to = 0);
        MyString operator+(MyString const &) const;
        MyString &operator=(MyString);
        MyString &operator=(char const[]);
        operator int() const { return M_size; }
        MyString &to_upper();
        MyString &to_lower();

        // Friends
        template <typename U>
        friend void swap(MyString<U> &, MyString<U> &);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &, MyString<U> const &);
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
    MyString<T> &MyString<T>::extend(size_t to)
    {
        MyString dummy(*this);
        alloc.deallocate(str, A_size);
        str = alloc.allocate(A_size < 1);
        do
        {
            A_size = A_size << 1;
        } while (A_size >= to);
        for (int it = 0; it < dummy.M_size; it++)
            *(str + it) = *(dummy.str + it);
        return *this;
    }

    template <typename T>
    MyString<T> MyString<T>::operator+(MyString<T> const &string) const
    {
        MyString result(*this);
        if (result.A_size < M_size + string.M_size)
            result.extend(M_size + string.M_size);
        for (int it = 0; it < string.M_size; it++)
            *(result.str + result.M_size + it) = *(string.str + it);
        result.M_size = M_size + string.M_size;
        return result;
    }

    template <typename T>
    MyString<T> &MyString<T>::to_lower()
    {
        for (int it = 0; it < M_size; it++)
        {
            if (*(str + it) <= 'Z' && *(str + it) >= 'A')
                *(str + it) += ('a' - 'A');
        }
        return *this;
    }

    template <typename T>
    MyString<T> &MyString<T>::to_upper()
    {
        for (int it = 0; it < M_size; it++)
        {
            if (*(str + it) <= 'z' && *(str + it) >= 'a')
                *(str + it) -= ('a' - 'A');
        }
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
    std::ostream &operator<<(std::ostream &os, MyString<T> const &string)
    {
        for (int it = 0; it < string.M_size; it++)
            os << *(string.str + it);
        return os;
    }

    // Useful Alias
    using string = MyString<>;
}