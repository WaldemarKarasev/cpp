#include <iostream>

int& foo()
{
    int* p = new int(199);
    std::cout << "p = " << p << std::endl;

    return *p;
}

int main()
{

    int& arr = foo();

    std::cout << "arr = " << arr << std::endl;
    std::cout << "&arr = " << &arr << std::endl;

    delete &arr;

}