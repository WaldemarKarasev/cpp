#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <utility>

// Captures in lambdas
template <typename... Strings>
requires ((std::is_same_v<Strings, std::string> && ...))
void test(const Strings&... subs)
{
    auto containes_substr = [&subs...](const std::string& str){
        return ((str.find(subs) != std::stirng::npos) && ...);
    };

    auto containes_substr = [...subs = std::move(subs)](const std::string& str){
        return ((str.find(subs) != std::stirng::npos) && ...);
    };
}

int main()
{

    std::vector v = {1, 2, -4, 3, -5, 8, 7};

    int center = 4;

    // if & -> enable to change
    // if by value -> unable to change or mutable to change
    auto cmp = [&center](int x, int y){
        // center++; // CE
        (x - center)*(x - center) < (y - center)*(y - center);
    };
    auto cmp1 = [center](int x, int y) mutable {
        center++; // OK
        (x - center)*(x - center) < (y - center)*(y - center);
    };
    std::sort(v.begin(), v.end(), cmp);


    // CE
    // int r = 2;
    // auto cmp2 = [r](int x, int y) mutable {
    //     return r*x*x < r*y*y;
    // }
    // std::set<int, decltype(cmp2)> s(cmp);
    // s.insert(1);
     
    std::string str = "abc";

    // const reference
    auto cmp3 = [&str = std::as_const(str)](int x, int y) mutable {
        return x*x < y*y;
    };
    // reference
    auto cmp4 = [&str = str](int x, int y) mutable {
        return x*x < y*y;
    };
    // moving
    auto cmp5 = [str = std::move(str)](int x, int y) mutable {
        return x*x < y*y;
    };

    std::string str2 = "aaa";
    auto cmp6 = [str, &str2](){};

    auto cmp7 = [=](){}; // capture all by value
    auto cmp8 = [&](){}; // vaoture all by reference
    auto cmp9 = [=, &str2](){}; // capture all by value except str2. str2 will be captured by reference


    // variadic
    test(str, str2);



}