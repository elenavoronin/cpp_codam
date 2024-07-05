#include "Contact.hpp"
#include <string>
#include <iostream>


Contact::Contact() {
    std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
    std::cout << "Contact destructor called" << std::endl;
}

void    Contact::set_first(std::string info) {
    Contact contact;
    contact.first_name = info;
}

void    Contact::set_last(std::string info) {
    Contact contact;
    contact.last_name = info;
}

void    Contact::set_nickname(std::string info) {
    Contact contact;
    contact.nickname = info;
}

void    Contact::set_phone(std::string info) {
    Contact contact;
    contact.phone_number = info;
}

void    Contact::set_secret(std::string info) {
    Contact contact;
    contact.darkest_secret = info;
}
