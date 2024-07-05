#include "Contact.hpp"
#include <string>
#include <iostream>


Contact::Contact() {
    std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
    std::cout << "Contact destructor called" << std::endl;
}

void    Contact::set_contact() {
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