#include <iostream>
#include <memory>


int main()
{	
	std::cout << sizeof(int*) << std::endl;
	std::cout << sizeof(long*) << std::endl;
	std::cout << sizeof(double*) << std::endl;
	std::cout << sizeof(std::shared_ptr<int>) << std::endl;
}
