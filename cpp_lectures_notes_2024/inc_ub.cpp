#include <iostream>


int main()
{
    int x = 0;

  std::cout << ( --x == x-- ) << std::endl;
  std::cout << ( x-- == --x ) << std::endl;


}