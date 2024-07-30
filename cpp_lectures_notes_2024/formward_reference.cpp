#include <iostream>
#include <type_traits>

// reference collapsing
/*
    & + &   -> &
    && + &  -> &
    & + &&  -> &
    && + && -> &&

*/

namespace lib {


template <typename T>
T&& forward(std::remove_reference_t<T>& value)
{
    return static_cast<T&&>(value);
}

template <typename T>
T&& forward(std::remove_reference_t<T>&& value) // for formwarding fron 
{
    return static_cast<T&&>(value);
}

template <typename T>
std::remove_reference_t<T>&& move(T&& value)
{
    return static_cast<remove_reference_t<T>&&>(value);
}

template <typename T>
? move_if_noexcept(? )
{
    return ?;
}

/*
!) Args = int&
    typeof(args) = int&
    T = int&;
    typeof(value) = int&

2) Args = int
   typeof(args) = int&&
   T = int
*/


} // namespace lib

int main()
{

}