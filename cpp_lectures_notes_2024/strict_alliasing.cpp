#include <iostream>


// Strint alliasing
// clang++ -O2 *.cpp
// exception - char

// voltile long long will solve this optimization
long long foo(long long* a, int* b)
{
    if (*a != 11)
        *b = 11;

    return *a;
}

int main()
{

    long long a = 22;

    a = foo(&a, (int*)&a);
    std::cout << a << std::endl;

}