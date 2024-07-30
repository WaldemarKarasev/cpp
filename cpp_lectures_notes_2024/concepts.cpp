#include <iostream>
#include <vector>
#include <string>
#include <type_traits>


// Concepts
template <typename T, typename U>
concept same_as = std::is_same_v<T, U>;


template <typename T>
concept InputIterator = requires(T it){
    {++it} -> std::same_as<T&>;
    typename std::iterator_traits<T>::value_type;
    {*it} -> std::convertible_to<typename std::iterator_traits<T>::value_type>;
};

// template <typename It, typename Predicate>
// requires InputIterator<It> && requires(Predicate p, It it){
//     p(*it);
// }
// template <InputIterator It, std::predicate<decltype(*std::declval<It>())> Pred>
//It find_if(It beg, It end, Pred pred)
InputIterator auto find_if(InputIterator auto beg, InputIterator auto end, std::predicate<decltype(*beg)> auto p)
{
    for (auto it = beg; it != end; ++it)
    {
        if (p(*it))
        {
            return it;
        }
    }
    return end;
}

int main()
{
    std::vector<int> v(10);

    find_if(v.begin(), v.end(), [](int x) { return x > 0; });
}