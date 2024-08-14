#pragma once
#include <string>


class Fixed {
    private:
    int                 number;
    static int const   fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed&);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);

};