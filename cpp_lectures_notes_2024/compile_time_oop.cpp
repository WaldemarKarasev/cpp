#include <array>
#include <iostream>


// OOP in compile time
struct S
{
    constexpr S(int x) : x(x) {}
    int x = 5;

    constexpr int getInt() { return x; }

    constexpr int getInt() const { return x + 1; }

    constexpr ~S() = default; // OK since c++20
};


template <S s>
struct MyClass {

    std::array<int, s.x> a;
    int x = s.getInt();

};

constexpr int f()
{
    S s = 10;
    return s.getInt();
}


struct Base
{
    int x = 0;
    constexpr virtual int f()
    {
        return x;
    }
};

struct Derived : Base
{
    constexpr virtual int f() override{ 
        return x + 1;
    }
};


constexpr int g(int x)
{
    Derived d;
    Base b;
    Base& bb = d;

    // dynamic_casr -> OK

    Base& b2 = x % 2 ? bb : b;
    return dynamic_cast<Derived&>(b2).x; // OK, or CE if error 
}

template <int N, std::invocable<int> auto F>
struct Checker 
{
    static_assert(F(N));
    std::array<int, N> a;
};

int main()
{
    // constexpr int y = g(0);
    // constexpr int z = g(1);

    // static_assert(y == 0);
    // static_assert(z == 1);


    // static_assert(f() == 10);
    // constexpr S s = 5;
    // static_assert(sizeof(MyClass<s>) == 24);


    constexpr auto is_prime = [](int n){
        
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0) return false;
        }
        return n > 1;
    }(179);

    constexpr bool is179prime = is_prime;

    static_assert(is179prime);


    constexpr Checker<5, [](int n){
        
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0) return false;
        }
        return n != 1;
    }> c{};

}