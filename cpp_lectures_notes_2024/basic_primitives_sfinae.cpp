#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
// Metafunctions, SFINAE, concepts and constraints.

// Basic primitive for template metaprogramming

template <typename T>
struct type_identity
{
    using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;
 
template <typename T, T val>
struct integral_constant
{
    static constexpr T value = val;
};

template <bool b>
using bool_constant = integral_constant<bool, b>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template <typename T>
struct is_lvalue_reference : false_type {};

template <typename T>
struct is_lvalue_reference<T&> : true_type {};

template <typename T>
using is_lvalue_reference_v = typename is_lvalue_reference<T>::value;

template <typename... Types>
struct conjunction
{
    static constexpr bool value = (Types::value && ...);
};

// SFINAE - subatituition error is not an E and std::enable_if

template <bool B, typename T = void>
struct enable_if{};

template <typename T>
struct enable_if<true, T>
{
    using type = T;
};

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;



template <typename T>
auto f(T) -> typename T::value_type
{
    std::cout << "1" << std::endl;
    return typename T::value_type();
}

// C-style variadic function
void f(int, ...)
{
    std::cout << "2" << std::endl;
}

// C++ style variadic function
template <typename... Types>
void f(Types...)
{
    std::cout << "3" << std::endl;
}

template <typename T, enable_if_t<std::is_integral_v<T>, bool> = true>
void g(T)
{
    std::cout << "11" << std::endl;
}

template <typename T, enable_if_t<!std::is_integral_v<T>, bool> = true>
void g(T)
{
    std::cout << "22" << std::endl;
}


namespace detail 
{
    template <class T>
    true_type test(int T::*);

    template <class>
    false_type test(...);
}

template <class T>
struct is_class : decltype(::detail::test<T>(nullptr)) {};

template <typename T>
static constexpr bool is_class_v = is_class<T>::value;


// Metafunctions implementation with usage of SFINAE

template <typename T>
typename std::add_rvalue_reference<T>::type declval();

namespace lib::detail
{
    // comma trick
    template <typename T, typename... Args>
    true_type test(decltype(std::declval<T>().construct(Args()...), nullptr));

    template <typename...>
    false_type test(...);
}

template <typename T, typename... Args>
struct has_methos_construct : decltype(lib::detail::test(<T, Args...>(nullptr))){}; {};

template <typename T, typename... Args>
const bool has_method_construct_v = has_method_construct<T, Args...>::value;

// is_copy_constructible
// ...
// is_base_of
// ...


// commont_type
template <typename... Types>
struct common_type;

template <typename T>
struct common_type<T> : std::type_identity<T> {};   

template <typename T, typename U>
struct common_type<T, U>
    : std::__type_identity<
        decltype(true ? std::declval<T> : std::declval<U>())
    > {};

template <typename T, typename... Types>
struct common_type<T, Types...>
    : common_type<T, common_type<Types...>::type {};



// SFINAE friendly https://stackoverflow.com/questions/35033306/what-does-it-mean-when-one-says-something-is-sfinae-friendly


int main()
{

    f(0);

    std::vector<int> v;
    f(v);

    g(9);
    g("abc");


    std::cout << is_class_v<std::string> << std::endl;
    std::cout << is_class<std::string>::value << std::endl;
    std::cout << false_type::value << std::endl;

}