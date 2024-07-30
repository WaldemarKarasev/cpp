#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>


struct S
{
    int a = 0;
    auto getLambda()
    {
        auto f = [this](int x)
        {
            return x + a;
        };

        // UB if f will be used after S object will be deleted
        // auto f = [=](int x)
        // {
        //     return x + a;
        // };

        return f;
    }
};




int main()
{
    S s;
    auto f = s.getLambda();
    std::cout << f(4) << std::endl;


    // UB
    S* s2 = new S();;
    auto f2 = s2->getLambda();
    delete s2;

    std::cout << f(4) << std::endl;


    static int x = 9;
    auto f3 = [=]() mutable {
        x++;
    }

    f3();
    std::cout << x << std::endl;

}