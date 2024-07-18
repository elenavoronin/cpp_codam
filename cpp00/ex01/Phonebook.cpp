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

    void Phonebook::add(Contact& contact) {
        if (contact.getDarkestSecret().empty() ||
        contact.getNickname().empty() ||
        contact.getPhoneNumber().empty() ||
        contact.getFirstName().empty() ||
        contact.getLastName().empty()) {
            std::cout << "Contact not added, fields can't be empty" << std::endl;
            return ;
        }
        int i = (this->getcount()  + 1) % 8;
        this->contacts[i] = contact;
        if (this->count < 8) {
            this->count++;
        } else {
            this->oldest = (this->oldest + 1) % 8;
     }
        std::cout << "Contact added" << std::endl;
    }

void    Phonebook::search() const {
    int index;
    std::cout << "Enter contact index" << std::endl;
    std::cin >> index;
    if (index < 1 || index > this->getcount()) {
        std::cout << "Wrong index" << std::endl;
        std::cin.ignore();
        return ;
    }
    if (this->getcount() == 0) {
        std::cout << "Phonebook is empty" << std::endl;
        std::cin.ignore();
        return ;
    }
    this->contacts[index].display(index - 1);
    std::cin.ignore();
}

void    Phonebook::setcount(int last) {
    Phonebook::count = last;
}

int    Phonebook::getcount() const {
    return this->count;
}

void   Phonebook::setoldest(int last) {
    Phonebook::oldest = last;
}

int    Phonebook::getoldest() const {
    return this->count;
}
