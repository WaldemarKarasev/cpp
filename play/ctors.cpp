#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class test
{
private:
    /* data */
public:

    test() { std::cout << "default test()" << std::endl; }
    test(int i) { std::cout << "ctor test(int)" << std::endl; m_i = i;};
    
    test(const test&) { std::cout << "copy ctor test(const test&)" << std::endl; };
    test& operator=(const test&) { std::cout << "copy assignment test" << std::endl; return *this; }

    test(test&&) { std::cout << "move ctor test(test&&)" << std::endl; };
    test& operator=(test&&) { std::cout << "move assignment test" << std::endl; return *this; }

    void operate(int i) { m_i = i; }
    ~test(){ std::cout << "~test(): m_i=" << m_i << std::endl;};

    int m_i{};
};


void foo() {}
test create()
{
    test t;
    t.operate(4);
    std::cout << "ff\n";
    foo();
    return t;
}

test& create(int)
{
    test t(733);
    return t;
}

test&& createMove()
{
    test t(66);
    return std::move(t);
}

template <typename T>
std::vector<T> createVec(int size, T val)
{
    std::vector<T> vec(size);
    std::fill(vec.begin(), vec.end(), val);
    return vec;
}

template <typename T>
std::vector<T>& createVecRef(int size, T val)
{
    std::vector<T> vec(size);
    std::fill(vec.begin(), vec.end(), val);
    return vec;
}

template <typename T>
std::vector<T>&& createVecMove(int size, T val)
{
    std::vector<T> vec(size);
    std::fill(vec.begin(), vec.end(), val);
    return std::move(vec);
}

std::string createStr(const char* str, int size)
{
    std::string str3(str, size);
    return std::move(str3);
}



int main()
{
    #if 0
    std::vector<int> vec;// = createVecMove<int>(100, 5);
    std::cout << vec.size() << "  " << std::endl;
    std::for_each(vec.begin(), vec.end(), [](const std::vector<int>::value_type& value){
        std::cout << value << " ";
    });
    
    std::string str = createStr("hello", 6);
    std::cout << str << std::endl;
    #endif
    {
        test t = createMove();
    }
    
    std::cout << "\n\nspace\n\n";

    {
        test t2 = create(9);
    }
}