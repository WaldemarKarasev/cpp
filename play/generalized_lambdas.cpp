#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

// Generelizaed (templated) lambdas

int main()
{
    std::map<std::string, int> m;
    m["abc"] = 1;
    m["cbf"] = 2;

    decltype(m) m2;

    auto f = [](auto& item) {
        ++item.second;
        return item;
    };

    std::transform(m.begin(), m.end(), std::inserter(m2, m2.begin()), f);

    auto f2 = [](auto& item)
        requires requires(decltype(item) a) { a.second; }
    {
        ++item.second;
        return item;
    };

    auto f3 = []<typename T>(T& item)
    requires requires(T a) { a.second; }
    {
        ++item.second;
        return item;
    };

    // since C++23
    // auto f4 = []<typename T>(T& item) mutable noexcept [[nodiscard]] -> T  
    // requires requires(T a) { a.second; }
    // {
    //     ++item.second;
    //     return item;
    // };


    // functional programming example

    // Ex 1
    auto sum = [](int x, int y){ return x + y; };

    // fix second argument
    auto fix_second_argument = [](auto&& f, auto&& second_arg){
        return [f = std::forward<decltype(f)>(f), second_arg = std::forward<decltype(second_arg)>   (second_arg)](auto first_arg){
            return f(std::forward<decltype(first_arg)>(first_arg), second_arg);
        };
    };

    auto sum_with_five = fix_second_argument(sum, 5);

    std::cout << sum_with_five(3) << std::endl; // must be 8
    
    // Ex 2
    auto print_hello = [](){ std::cout << "hello" << std::endl; };

    auto do_twice = [](auto&& f) {
        return [f = std::forward<decltype(f)>(f)](const auto&... args)
        {
            f(args...);
            f(args...);
        };
    };

    auto print_hello_hello = do_twice(print_hello);

    print_hello_hello();


    // Recursive lambdas

    // CE
    // auto fibinacci = [](int n){
    //     return n > 2 ? fibonacci(n - 1) + fibonacci(n - 2) : 1;
    // }

    // deducing this since C++23
    auto fibinacci = []<typename T>(this T& self, int n){
        return n > 2 ? self(n - 1) + self(n - 2) : 1;
    };
    
    auto fibinacci1 = [](this auto& self, int n) -> int{
        return n > 2 ? self(n - 1) + self(n - 2) : 1;
    }