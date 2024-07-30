#include "pch.h"

void print()
{
    std::cout << "hello\n";
}

int main() {

    #if 0
    std::optional<int> a;
    a.emplace(1);
    std::cout << a.value() << std::endl;
    std::thread th(print);
    #else 
    std::cout << "1\n";
    std::optional<std::thread> storage;
    std::cout << "2\n";
    storage.emplace([](){
        std::cout << "3\n";
        print();
        std::cout << "4\n";
    });
    std::cout << "5\n";
    
    storage.value().join();


    #endif
    
    
}