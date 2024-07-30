#include <iostream>


template <typename T, typename U>
void f(T, U)
{
	std::cout << "1\n";
}

template <>
void f(int, int)
{
	std::cout << "3\n";
}

template <typename t, typename T>
void f(T, T)
{
	std::cout << "3\n";
}

void f(int, int)
{
	std::cout << "4\n";
}

int main()
{
	f(0, 0);
}
