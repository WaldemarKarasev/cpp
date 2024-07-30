#include <iostream>

template <typename T>
void f(T x)
{
	std::cout << "1\n";
}

template <typename T>
T f(T x)
{
	std::cout << "2\n";
	return 0;
}

////
template <typename T>
void g(T x)
{
std::cout << "1\n";
}

template <typename T>
void g(T& x)
{
std::cout << "2\n";
}

int main()
{
	int x = 0;
//	int i = f(x);

	int& y = x;
	g(y);
}
