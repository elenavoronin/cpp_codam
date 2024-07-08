#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

Phonebook::Phonebook() {
    // std::cout << "Phonebook constructor called" << std::endl;
}

Phonebook::~Phonebook() {
    // std::cout << "Phonebook destructor called" << std::endl;
}

void Phonebook::add() {
    Phonebook   phonebook;
    Contact     contact;
    int         i = phonebook.last;

    if (phonebook.last == 8) {
        i = 1;
        phonebook.index = 0;
    }
    else if (!phonebook.last) {
        i = 1;
        phonebook.index = 0;
    }
    phonebook.contacts[i].setContact();
    phonebook.index = phonebook.index + 1;
    phonebook.last = phonebook.last + 1;
    std::cout << "Contact added" << std::endl;
}

void    Phonebook::search() const {
    int index;
    std::cout << "Enter contact index" << std::endl;
    std::cin >> index;
    if (index < 1 || index > 8) {
        std::cout << "Wrong index" << std::endl;
        std::cin.ignore();
        return ;
    }
    if (this->getlast() == 0) {
        std::cout << "Phonebook is empty" << std::endl;
        std::cin.ignore();
        return ;
    }
    this->contacts[index].display();
    std::cin.ignore();
}

void    Phonebook::setlast(int last) {
    Phonebook::last = last;
}

int    Phonebook::getlast() const {
    return this->last;
}

void    Phonebook::setindex(int index) {
    Phonebook::index = index;
}

int    Phonebook::getindex() const {
    return this->index;
}

