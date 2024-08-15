#pragma once
#include <string>


class Fixed {
    private:
    int                 number;
    static int const    fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed(const int number1);
        Fixed(const float number2);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

        // copy assignment operator overload
        Fixed& operator=(const Fixed&);

        // arithmetic operator overload
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);

        // comparison operator overload
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // increment/decrement operator overload
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed& number1, Fixed& number2);
        static  const Fixed& min(const Fixed& number1, const Fixed& number2);
        static Fixed& max(Fixed& number1, Fixed& number2);
        static const Fixed& max(const Fixed& number1, const Fixed& number2);
        
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);
