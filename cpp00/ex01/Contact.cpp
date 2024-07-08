#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>


Contact::Contact() {
    // std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
    // std::cout << "Contact destructor called" << std::endl;
}

void    Contact::setContact() {
    Contact contact;
    
    std::cout << "Enter first name" << std::endl;
    std::getline(std::cin, contact.first_name);

    std::cout << "Enter last name" << std::endl;
    std::getline(std::cin, contact.last_name);

    std::cout << "Enter nickname" << std::endl;
    std::getline(std::cin, contact.nickname);

    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin, contact.phone_number);

    std::cout << "Enter darkest secret" << std::endl;
    std::getline(std::cin, contact.darkest_secret);
}


std::string   Contact::getFirstName() const {
    return this->first_name;
}

std::string   Contact::getLastName() const {
    return this->last_name;
}

std::string   Contact::getNickname() const {
    return this->nickname;
}

std::string   Contact::getPhoneNumber() const {
    return this->phone_number;
}   

std::string   Contact::getDarkestSecret() const {
    return this->darkest_secret;
}

void    Contact::display() const {
    std::cout << std::setw(10) << "index" << "|" 
            << std::setw(10) << "first name" <<  "|" 
            << std::setw(10) << "last name" << "|" 
            << std::setw (10) << "nickname" << std::endl;
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
}