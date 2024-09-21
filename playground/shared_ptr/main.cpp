#include <iostream>
#include <thread>
#include <memory>
#include <string>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    std::cout << std::thread::hardware_concurrency() << std::endl;

    std::shared_ptr<std::string> str_ptr = std::make_shared<std::string>("Hello long long long long long string for the heap allocation");


    std::vector<std::thread> thread_pool;
    for (int i = 0; i < std::thread::hardware_concurrency()*10; ++i)
    {
        thread_pool.push_back(std::thread([&str_ptr, i](){
            str_ptr = std::make_shared<std::string>("Hello" + std::to_string(i));
            auto local_ptr = str_ptr;
            // local_ptr.reset();
            str_ptr->clear();
            str_ptr = std::make_shared<std::string>("Hello" + std::to_string(i));
            str_ptr = std::make_shared<std::string>("Hellowde" + std::to_string(i));
            str_ptr = std::make_shared<std::string>("Hellowdwed" + std::to_string(i));
            std::this_thread::sleep_for((i/100)*200ms);
            std::this_thread::yield();
        }));
    }


    for (int i = 0; i < std::thread::hardware_concurrency()*10; ++i)
    {
        thread_pool[i].join();
    }

    std::cout << *str_ptr << std::endl;
    std::cout << "End" << std::endl;

}