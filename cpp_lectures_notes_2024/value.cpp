/*

         glvalue            rvalue
        /       \          /      \
     lvalue        xvalue       prvalue

*/


/*                      prvalue 
    std::string s =  std::string("abc"); // copy elision. only one string is created
                            xvalue
    std::string s =  std::move(std::string("abc")); // two string are created

    since c++17 garentie copy elision


    string f()
    {
        return string("abc"); // copy elision prvalue
    }

    string f()
    {
        return std::move(string("abc")); // no copy elision xvalue
    }
*/
#include <iostream>

struct S
{
    int x = 0;
    S(int x) : x(x) {
        std::cout << "Created" << std::endl;
    }
    S(const S& s) : x(s.x) {
        std::cout << "Copy" << std::endl;
    }
    S(S&& s) : x(s.x) {
        std::cout << "Move" << std::endl;
    }
    ~S() {
        std::cout << "Destroyed" << std::endl;
    }
};

struct T {
    T(S){}
};

// RVO - Return Value Optimization
S f()
{
    S s(5);

    return s;
}

S f(S s)
{
    return s;
}

S f(S&& s)
{
    return std::move(s);
}

int main()
{
    //S s = S(S(S(S(4))));

    // temporary materialization. from prvalue -> xvalue
    //S s = std::move(S(S(S(S(4)))));

    //T t = std::move(S(S(S(S(S(S(5)))))));

    //S s = f(); // RVO

    S t(3);
    S s = f(t); // RVO

}
