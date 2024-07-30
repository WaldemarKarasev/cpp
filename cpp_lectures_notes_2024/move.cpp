#include <iostream>
#include <type_traits>

struct A
{
    A() { std::cout << "A()" << std::endl; }
    A(const A&) { std::cout << "A(const A&)" << std::endl; }
    A& operator=(const A&) { std::cout << "A::operator=(const A&)" << std::endl; return *this; }

    A(A&&) { std::cout << "A(A&&)" << std::endl; }
    A& operator=(A&&) { std::cout << "A::operator=(A&&)" << std::endl; return *this; }

    ~A() { std::cout << "~A()" << std::endl; }

    void trunk(A&&) {}
    void func() {}
};

namespace lib {
    template <typename T>
    constexpr T&& forward(T&& value) noexcept
    {
        return static_cast<T&&>(value);
    }

    template <typename T>
    constexpr std::remove_reference_t<T>&& move(T&& value)
    {
        return static_cast<typename std::remove_reference_t<T>&&>(value);
    }
}

int main()
{   
    A a;
    //A a2(A(lib::forward(lib::move(a))));
    //A a3(A(lib::forward(a)));

    A a2;
    a2.trunk(std::forward(A()));

    a.func();


}