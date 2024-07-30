#include <iostream>
#include <vector>


#if 0
int& foo()
{
    int* p = new int(199);
    std::cout << "p = " << p << std::endl;

    return *p;
}
#endif

int main()
{

    //int& arr = foo();
    //std::cout << "arr = " << arr << std::endl;
    //std::cout << "&arr = " << &arr << std::endl;
    //delete &arr;


    std::vector<int> vec(10);
    //vec[14] = 10;

    int* ptr = new int[100]();
    int* ptr2 = new int[100]();
    int* ptr3 = new int[100]();

}