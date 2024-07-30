#include <iostream>
#include <string>


// Unions and their usafe

union U
{
    int x;
    double y;
    std::string s;

    //U(){};
    //~U(){};
};

int main()
{
    U u;
    u.x = 5;
    u.y = 2.45;
    std::cout << u.x << std::endl;

    new (&u.s) std::string("abc");
    std::cout << u.s << std::endl;

    u.s.~basic_string<char>();
    u.x = 5;

}