#include "Fixed.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}


// int main (void)
// {
//     Fixed A(2);
//     Fixed B(10);

//     std::cout << A << std::endl;
//     std::cout << B << std::endl;
//     std::cout << A/B << std::endl;
//     std::cout << B/A << std::endl;
//     std::cout << A++ << std::endl;
//     std::cout << A << std::endl;
//     std::cout << ++A << std::endl;
//     std::cout << A << std::endl;


// }