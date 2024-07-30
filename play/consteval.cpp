#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

// consteval


constexpr bool is_prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0) return false;
    }
    return x > 1;
}


template <int Num>
consteval std::array<int, Num> primeNumbers()
{
    std::array<int, Num> primes;
    int idx = 0;
    for (int val = 1; idx < Num; ++val)
    {
        if (is_prime(val))
        {
            primes[idx++] = val;
        }
    }

    return primes;
}


int main()
{
    auto primes = primeNumbers<5>();

    // is_constant_evaluated -- no constexpr
}