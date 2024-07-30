#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

// Lambdas, closures and elements of functional programming



int main()
{
    std::vector v = {2, 5, 7, -5, 3};

    // expresion == lambda, cmp == closure object, closure == type of cmp
    auto cmp = [](int x, int y){ return x < y; };

    // CE
    // auto cmp = [](int x, int y){ 
    //     if (x > y)
    //         return 1;
    //     else    
    //         return 1u;
    // };


    // OK
    auto cmp2 = [](int x, int y) -> int { 
        if (x > y)
            return 1;
        else    
            return 1u;
    };

    auto hello = []{
        std::cout << "Hello World!" << std::endl;
    };  

    // Immediate invocation
    []{
        std::cout << "Hello World!" << std::endl;
    }();  
    // using case 1
    const int& x = [](int y)
    {
        if (y == 2)
        {
            return y / 2;
        }
        else 
        {
            return 3;
        }(200);
    }

    // using case 2
    // in initializer list


    std::cout << typeid(cmp).name() << std::endl;

    std::sort(v.begin(), v.end(), [](int x, int y){
        return x*x < y*y;
    });

    std::for_each(v.begin(), v.end(), [](int x){
        std::cout << x << " ";
    });


    std::set<int, decltype(cmp)> s;


    s.insert(-1);
    s.insert(23);




    // Positive lambda hack
    auto c_func = +[](int x){ return x*x; } // casting closure to c-pointer
}