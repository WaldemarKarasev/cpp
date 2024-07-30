#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>


// std::function usage and naive implemetation

int square(int x) { return x * x; }

struct AddOne
{
    int operator()(int x)
    {
        return x + 1;
    }
};

struct Strange
{
    int c = 7;
    int modulo(int x) {
        return x % c;
    }
};  

int main()
{
    std::function<int(int)> f = square;
    std::function<int(int)> f2 = AddOne();
    std::function<int(int)> f3 = [](int x) {return x + 2;};

    auto f4 = f;
    f = AddOne();

    std::function<int(Strange&, int)> ff = &Strange::modulo;
    Strange s{4};
    ff(s, 5);   

    std::function<int(Strange&)> fff = &Strange::c;
    std::cout << "fff(s) - " << fff(s) << std::endl;

}