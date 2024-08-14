#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

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
        this->number = copy.getRawBits();
    return *this;
}

Fixed:: Fixed(const int number1) {
    std::cout << "Int constructor called" << std::endl;
    this->number = number1;
}

Fixed:: Fixed(const float number2) {
    std::cout << "Float constructor called" << std::endl;
    number = number2;
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

float Fixed:: toFloat( void ) const {

}

int Fixed:: toInt( void ) const {

}