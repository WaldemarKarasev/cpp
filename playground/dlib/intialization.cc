#include <iostream>

class TestClass
{
public:
    TestClass()  {std::cout << "Default constructor\n";}
    ~TestClass() {std::cout << "Destructor\n";}
};

int main()
{
    TestClass obj = {};
}
