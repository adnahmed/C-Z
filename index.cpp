// The Curiously Recurring Template Pattern (CRTP)
template <class T>
class BaseT
{
    // method in Base can use template to access members of Derived
};

class DerivedT : public BaseT<Derived>
{
};

#include <iostream>

// static polymorphism
class Base
{
public:
    virtual void method()
    {
        std::cout << "Derived";
    }
};

class Derived : public Base
{
public:
    virtual void method()
    {
        std::cout << "Derived";
    }
}

template <class Derived>
struct base
{
    void interface()
    {
        static_cast<Drived *>(this)->implementation();
    }
};

struct derived : base<derived>
{
    void implementation()
    {
    }
};
// A class template to express an equality comparision interface.
template <typename T>
class equal_comparable
{
    friend bool operator==(T const &a, T const &b)
    {
        return !a.equal_to(b);
    }
}

// Class value_type wants to have == and !=, so it derives from
// equal_comparable with itself as argument (which is the CRTP)
class value_type : private equal_comparable<value_type>
{
public:
    bool equal_to(value_type const &rhs) const; // to be defined
}

int
main()
{
    Base *pBase = new Derived;
    pBase->method();
    delete pBase;
    return 0;
}