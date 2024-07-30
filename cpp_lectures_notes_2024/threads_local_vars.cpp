#include <thread>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

int this_var;

int main() {
    std::thread th1([](){
        this_var = 3;
        std::this_thread::sleep_for(400ms);
        std::cout << std::this_thread::get_id() << " - " << this_var << std::endl;
    });


    std::thread th2([](){
        std::this_thread::sleep_for(10ms);
        this_var = 13244;
        std::this_thread::sleep_for(1000ms);
        std::cout << std::this_thread::get_id() << " - " << this_var << std::endl;
    });

    #if 0
    std::thread th3([](){
        this_var = -4;
        std::cout << std::this_thread::get_id() << " - " << this_var << std::endl;
    });
    #endif

    th1.join();
    th2.join();
    //th3.join();
}