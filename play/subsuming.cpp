#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <type_traits>
#include <concepts>

// Subsuming
// P.S. equivalence_relation
template <typename T>
concept InputIterator = requires(T x) 
{
    *x;
    ++x;
};

template <typename T>
concept ForwardIterator = InputIterator<T>
&& requires(T x)
{
    x++;
};

template <typename T>
concept BidirectionalIterator = ForwardIterator<T>
&& requires(T x)
{
    --x;
    x--;
};


template <typename T>
concept RandomAccessIterator = BidirectionalIterator<T>
&& requires(T x, T y)
{
    x - y;
    x < y; x > y; x <= y; x >= y;
    x += 1; x -= 1;
    x + 1; x - 1; 1 + x;
};


template <InputIterator Iter>
void my_advance(Iter& iter, size_t n)
{
    std::cout << "InputIterator" << std::endl;
    for (size_t i = 0; i < n; ++i)
    {
        ++iter;
    }
}

template <RandomAccessIterator Iter>
void my_advance(Iter& iter, size_t n)
{
    std::cout << "RandomAccessIterator" << std::endl;
    iter += n;
}

int main()
{
    std::vector<int> v(10);
    auto vit = v.begin();
    my_advance(vit, 5);

    std::list<int> l(10);
    auto lit = l.begin();
    my_advance(lit, 5);

}