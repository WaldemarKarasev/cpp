#include <iostream>
#include <vector>

// CTAD - Class Template Argument Deduction

template <typename T>
struct Debug
{
    Debug() = delete;
};


template <typename T>
struct vector
{
    template <typename Iter>
    vector(Iter, Iter) {}
};

// Explicit template deduction guides
template <typename Iter>
vector(Iter, Iter)
    -> vector<typename std::iterator_traits<Iter>::value_type>;

template <typename T, typename U>
struct S
{
    T x;
    U y;
};

// struct A {};
// struct B {};

// template <typename T, typename U>
// struct S : T, U {};

// template <typename.. Args>
// struct S : Args... {};
// template <typename.. Args>
// S(Args...) -> S<Args...>;;



// template <typename T, typename U>
// S(T, U) -> S<T,U>; 

int main()
{
    std::vector v = {1, 2, 3, 4, 5};
    //Debug<decltype(v)> d;

    vector v2(v.begin(), v.end());
    //Debug<decltype(v2)>();

    S s{1, 2.0}; // success since c++20
    //S s{A(), B()};
}