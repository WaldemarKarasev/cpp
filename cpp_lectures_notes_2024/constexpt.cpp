#include <iostream>


// Compile-time computations

// Basic usages of constexpr

constexpr int max(int x, int y)
{
    return x > y;
}

constexpr bool is_prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0) return false;
    }

    // CE
    // try {
    //     if (x > 100000)
    //     {
    //         throw 1; // if true ==> CE
    //     } 
    // } catch (...)
    // {

    // }
    return x > 1;
}
constexpr int count_primes()
{
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 0;
    for (int* p = a; p < a + 11; ++p)
    {
        count += is_prime(*p);
    }
    return count++ + ++count;
    //return count;
}



int main()
{
    constexpr int x = 5;
    constexpr int r = max(5, 6);
    static_assert(is_prime(37));
    //static_assert(count_primes() == 4);
}