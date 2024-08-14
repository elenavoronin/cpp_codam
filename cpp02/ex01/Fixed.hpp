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
        Fixed& operator=(const Fixed&);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &copy);