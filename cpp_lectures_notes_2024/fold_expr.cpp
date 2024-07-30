#include <iostream>
#include <type_traits>


// fold expressions (since c++17)

template <typename... Types>
struct all_pointers
{
	static constexpr bool value = (std::is_pointer_v<Types> && ...);
};


template <typename Head, typename... Tail>
struct is_homogeneous 
{
	static constexpr bool value = (std::is_same_v<Head, Tail> && ...);
};

template <typename... Args>
void printer(Args&&... args)
{
	(std::cout << ... << args) << std::endl;
}

int main()
{
	std::cout << all_pointers<int*, double*>::value << std::endl;
	std::cout << is_homogeneous<int, int>::value << std::endl;
	std::cout << is_homogeneous<double, int>::value << std::endl;
	printer("hello", "abc", 1, 2.0);
}
