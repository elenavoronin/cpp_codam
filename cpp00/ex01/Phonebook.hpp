#pragma once

#include "Contact.hpp"
#include <string>

class Phonebook{
    private:
        Contact contacts[8];
        int     index;
        int     last;

    public:
        Phonebook();
        ~Phonebook();
        void    add();
        void    search() const;
        void    setindex(int index);
        int     getindex() const;
        void    setlast(int last);
        int     getlast() const;
};
