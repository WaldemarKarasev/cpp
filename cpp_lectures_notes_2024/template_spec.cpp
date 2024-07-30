#include <iostream>

// full specialization
template <typename T>
class vector
{
	T* arr;
	size_t sz;
};

template <>
class vector<bool>
{
	char* arr;
	size_t sz;
};



// partial specialization
template <typename T, typename U>
struct S{};

template <typename W>
struct S<W, W> {};
// struct S<int, W>{};

int main()
{
}
