#include <bits/stdc++.h>

int main()
{
    std::function<void()> fun;


    auto fun2 = fun;

    std::atomic<size_t> count{0};

    auto res = count.fetch_add(1);
    std::cout << res << std::endl;

    res = count.fetch_sub(1);
    std::cout << res << std::endl;
    
}