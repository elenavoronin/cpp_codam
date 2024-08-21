#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>

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
        int i = (this->getoldest()) % 8;
        this->contacts[i] = contact;
        if (this->count < 8)
            this->count++;
        this->oldest++;
        if (this->oldest  == 8) {
            this->oldest = 0;
        }
        std::cout << "Contact added" << std::endl;
    }

bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void    Phonebook::search() const {
    std::string index;
    int ind;
    
    if (this->getcount() == 0) {
        std::cout << "Phonebook is empty" << std::endl;
        return ;
    }
    this->printcontacts();
    std::cout << "Enter contact index" << std::endl;
    std::getline(std::cin, index);
    if (isNumber(index) == false) {
        std::cout << "Wrong index, please enter a number" << std::endl;
        return ;
    }
    else {
        try {
            ind = std::stoi(index);
        }
        catch (const std::out_of_range& e) {
             std::cout << "Invalid input: Not a number" << std::endl;
            return ;
        }
    }
    if (ind < 1 || ind > (this->getcount())) {
        std::cout << "Wrong index, enter a positive integer" << std::endl;
        return ;
    }
    this->contacts[ind - 1].display();
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
    return this->oldest;
}

void    Phonebook::printcontacts() const {
    std::cout << std::setw(10) << "index" << "|" 
        << std::setw(10) << "first name" <<  "|" 
        << std::setw(10) << "last name" << "|" 
        << std::setw (10) << "nickname" << std::endl;
    for (int i = 0; i < this->getcount(); i++) {
        this->contacts[i].print(i);
    }
}