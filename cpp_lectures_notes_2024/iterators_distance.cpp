#include <iostream>
#include <iterator>
#include <vector>


template <typename InputIterator>
void find_most_often_number(InputIterator begin, InputIterator end)
{
    typename std::iterator_traits<InputIterator>::value_type x = *begin;
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance(Iterator first, Iterator last)
{
    if constexpr (std::is_base_of_v<
            std::random_access_iterator_tag,
            typename std::iterator_traits<Iterator>::iterator_category
            >)
    {
        return last - first;
    }

    int i = 0;
    for (; first != last; ++i, ++first);
    return i;
}

// trick to receive from compiler real type T at compile time as CE
template <typename T>
void f(T) = delete;

int main()
{
    std::vector<bool> vb(10);
    f(*vb.begin()); // trick to receive from compiler real type T at compile time as CE

}