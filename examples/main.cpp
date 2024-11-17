#include <bits/stdc++.h>

int main()
{
    std::cout << std::thread::hardware_concurrency() << std::endl;
    std::cout << sysconf(_SC_PAGESIZE) << std::endl;
}