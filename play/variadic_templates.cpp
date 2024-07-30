#include <iostream>
#include <type_traits>

// variadic templates
void print(){}

template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail)
{
	std::cout << head << "\n";
	std::cout << sizeof...(tail) << std::endl;
	print(tail...);
}
//

template <typename First, typename Second, typename... Types>
struct is_homogeneous 
{
	static constexpr bool value = std::is_same_v<First, Second>
								&& is_homogeneous<Second, Types...>::value;
};

template <typename First, typename Second>
struct is_homogeneous<First, Second>
{
	static constexpr bool value = std::is_same_v<First, Second>;
};


int main()
{
	print(1, 2.0, "abc");

	std::cout << is_homogeneous<int, int, int>::value << std::endl;
	std::cout << is_homogeneous<int, double, int, int>::value << std::endl;

}
