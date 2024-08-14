#include "Fixed.hpp"
#include <iostream>
#include <string>


Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignmnet operator called" << std::endl;
    if (this != &copy)
        number = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed:: getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void Fixed:: setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    number = raw;
}