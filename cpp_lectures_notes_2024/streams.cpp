#include <iostream>

// Streams

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);

    std::cout << "Message" << std::endl;
    std::cerr << "Error" << std::endl;

    int x;
    std::cout << 123;
    std::cin >> x;
    std::cout << x + 5;



}