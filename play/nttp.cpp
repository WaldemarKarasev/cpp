#include <iostream>

// Non-type template parameters.

template <typename T, size_t N>
class array{
	T arr[N];
};

template <size_t M, size_t N, typename Field = Rational>
class Matrix{};

template <typename Field, size_t N>
using SquareMatrix = Matrix<N, N, Field = Rational>;

template <size_t M, size_t K, size_t N, typename Field>
Matrix<M, N, field> operator*(const Matrix<M, K, Field>& a, const Matrix<K, N, Field>& b);

// template template parameters
template <typename T, template<typename, typename> class Container>
class Stack {
	Container<T, std::allocator<T>> container;
};



int main()
{
	array<int, 100> a;
	Stack<int, sta::vector> s;
}
