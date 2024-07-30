#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <memory>

// Constraints and requirements. (since C++20)

template <typename T, typename std::enable_if_t<std::is_class_v<T>, bool> = true>
void f(const T& x)
{
    std::cout << "1" << std::endl;

}

template <typename T, typename std::enable_if_t<std::is_class_v<T>, bool> = true>
void f(T x)
{
    std::cout << "2" << std::endl;

}

// since C++20
template <typename T>
requires std::is_class_v<T> && std::is_copy_constructible_v<T>
void g(const T& x)
{
    std::cout << "3" << std::endl;
}


template <typename T, size_t N>
requires (N <= 1'000'000)
struct array
{
    T stt[N];
};



// Requires-expression

// simple requirement
template <typename T>
requires requires(T a, T b){ a + b; }
T add(const T& a, const T& b)
{
    return a + b;
}

template <typename T>
void test()
{
    std::cout << requires(T a, T b) { a + b; } << std::endl;
}

// nested requirement
template <typename T, size_t N>
requires requires(T a){
    requires sizeof(T) == N;
}
void foo(const T& a){}


struct S
{
    bool operator==(const S&) & = delete;
    bool operator==(const S&)  { return true; };

};

// type requirement
template <typename T>
requires requires(T a){
    typename T::value_type;
    std::hash<T>()(a);
}
void boo(const T& a){}

int main()
{
    //g(0);
    //g(std::unique_ptr<int>(new int(4)));
    test<int>();
    test<std::string>();
    test<void>(); // clang - error, g++ - OK
    test<std::vector<int>>();
    foo<int, 4>(0);

    std::vector<int> v;
    boo<std::vector<int>>(v);
    //add(std::unique_ptr<int>(new int(4)), std::unique_ptr<int>(new int(4)));

}