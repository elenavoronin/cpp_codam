#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const Fixed& copy) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy) {
    // std::cout << "Copy assignmnet operator called" << std::endl;
    if (this != &copy)
        this->number = copy.getRawBits();
    return *this;
}

Fixed:: Fixed(const int number1) {
    // std::cout << "Int constructor called" << std::endl;
    this->number = number1 << this->fractionalBits;
}

Fixed:: Fixed(const float number2) {
    // std::cout << "Float constructor called" << std::endl;
    this->number = roundf(number2 * (1 << this->fractionalBits));
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed:: getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void Fixed:: setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    number = raw;
}

float Fixed:: toFloat( void ) const {
    return static_cast<float>(this->number) / (1 << this->fractionalBits);
}

int Fixed:: toInt( void ) const {
    return this->number >> this->fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

// arithmetic operator overload
Fixed Fixed::operator+(const Fixed& other) {
    return Fixed(this->number + other.number);
}
Fixed Fixed::operator-(const Fixed& other) {
    return Fixed(this->number - other.number);;

}
Fixed Fixed::operator*(const Fixed& other) {
    return Fixed(this->toFloat() * other.toFloat());

}
Fixed Fixed::operator/(const Fixed& other) {
    return Fixed(this->toFloat() / other.toFloat());
}

// comparison operator overload
bool Fixed::operator>(const Fixed& other) const {
    return this->number > other.number;
}
bool Fixed::operator<(const Fixed& other) const {
    return this->number < other.number;
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->number >= other.number;
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->number <= other.number;
}
bool Fixed::operator==(const Fixed& other) const {
    return this->number == other.number;

}
bool Fixed::operator!=(const Fixed& other) const {
    return this->number != other.number;
}

// increment/decrement operator overload
Fixed& Fixed::operator++() {
    ++number;
    return *this;
}
Fixed& Fixed::operator--() {
    --number;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    number++;
    return temp;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    number++;
    return temp;
}


Fixed& Fixed:: min(Fixed& number1, Fixed& number2) {
    if (number1 < number2)
        return number1;
    else
        return number2;
}

const Fixed& Fixed:: min(const Fixed& number1, const Fixed& number2) {
    if (number1 < number2)
        return number1;
    else
        return number2;
}

Fixed& Fixed:: max(Fixed& number1, Fixed& number2) {
    if (number1 < number2)
        return number2;
    else
        return number1;
}

const Fixed& Fixed:: max(const Fixed& number1, const Fixed& number2) {
    if (number1 < number2)
        return number2;
    else
        return number1;
}