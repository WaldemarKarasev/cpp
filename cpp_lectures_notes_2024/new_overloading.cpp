#include <iostream>
#include <vector>
#include <string>
// operator new overloading
// new: 1. memory allocation 2. object construction 
// in c++ enable overloading only first stage


void* operator new(size_t n)
{
    std::cout << n << " bytes allocated" << std::endl;
    return malloc(n);
}

void operator delete(void* ptr)
{
    std::cout << "deallocated" << std::endl;
    free(ptr);
}

void* operator new[](size_t n)
{
    std::cout << n << " bytes allocated []" << std::endl;
    return malloc(n);
}

void operator delete[](void* ptr)
{
    std::cout << "deallocated []" << std::endl;
    free(ptr);
}


struct Example
{
    int* x;
    Example() : x(new int){}
    ~Example() { delete x; }
};



int main()
{

    // OK
    //Example* example = reinterpret_cast<Example*>(new char[sizeof(Example)]);
    //new (example) Example();

    Example* example = new Example[1]; // Not OK, but why

    example[0].~Example();
    operator delete[](example);



#if 0
    std::vector<int> v;
    for (int i = 0; i < 50; ++i)
    {
        v.push_back(i);
    }

    int* p = new int[10];
    delete[] p;

    std::cout << sizeof(std::string) * 10 << std::endl;

    std::string* str_ptr = new std::string[10];
    delete[] str_ptr;
#endif
}