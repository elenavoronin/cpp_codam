#pragma once

#include "Contact.hpp"
#include <string>

class Phonebook{
    private:
        Contact contacts[8];
        int     count;
		int		oldest;

    public:
        Phonebook();
        ~Phonebook();
        void    add(Contact& contact);
        void    search() const;
        void    setcount(int last);
        int     getcount() const;
		void	setoldest(int last);
		int		getoldest() const;
        void    printcontacts() const;
};
