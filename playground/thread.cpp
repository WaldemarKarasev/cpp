#include <iostream>
#include <thread>


int CurrentInt = 1;

void PrintAddress() {
    std::cout << &CurrentInt << std::endl;
}

int main() {

    std::thread th1(PrintAddress);
    std::thread th2(PrintAddress);

    th1.join();
    th2.join();

}
