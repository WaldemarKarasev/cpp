#include <iostream>
#include <string>
#include <variant>
#include <exception>

class MyException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "MyException is thrown!";
    }
};

void ThrowExceptionFunc(std::variant<std::string, std::exception_ptr>& box) {
    
    std::string str = "result string";

    try
    {
        throw MyException();   
    }
    catch(const std::exception& e)
    {
        box = std::current_exception();
        return;   
    }
    
    box = str;
    return;

}


int main()
{
    #if 0
    std::variant<std::string, std::exception_ptr> box;

    try {
        throw std::exception();
    } catch(...) {
        box = std::current_exception();
    }
    std::cout << std::get_if<std::string>(&box) << std::endl;
    std::cout << std::get_if<std::exception_ptr>(&box) << std::endl;
    #endif

    std::variant<int, std::string> variant;

    variant = 3;

    std::cout << std::get<std::string>(variant);
    
}