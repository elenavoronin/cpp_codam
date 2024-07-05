#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class Phonebook{
    private:
        Contact contacts[8];

    public:
        Phonebook();
        ~Phonebook();
        void    add(std::string info, int i);
        void    search(std::string info);
        void    exit();

};

#endif