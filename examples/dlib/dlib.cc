#include "dlib.h"
#include <iostream>
dlib::dlib() { std::cout << "dlib default constructor" << std::endl; }
int dlib::square(int a)
{	
    std::cout << "square of number " << a << " is " << a * a << std::endl;
    return a * a;
}
