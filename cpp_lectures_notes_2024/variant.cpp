#include <iostream>
#include <variant>
#include <string>
#include <type_traits>

// Variant since C++17
// std::visit
// overload pattern
int main() 
{
    std::variant<int, double, std::string> v;
    std::variant<int, double, std::string> v2;

    v2 = 2;


    std::cout << std::get<int>(v) << std::endl;
    v = 3.14;

    // ctor
    v = "abc";
    // assign
    v = "qqq";

    std::visit([]<typename T>(const T& item) -> int{
        if constexpr (std::is_same_v<T, int>){
            std::cout << "int - " << item << std::endl;
        }
        else {
            std::cout << "not int - " << item << std::endl;
        }

        return 0;
    }, v2);

}