#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdio.h>


Contact::Contact() {
    // std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
    // std::cout << "Contact destructor called" << std::endl;
}

void    Contact::setContact() {
    std::string input;
    
    std::cout << "Enter first name" << std::endl;
    std::getline(std::cin, input);
    this->first_name = input;

    std::cout << "Enter last name" << std::endl;
    std::getline(std::cin, input);
    this->last_name = input;

    std::cout << "Enter nickname" << std::endl;
    std::getline(std::cin, input);
    this->nickname = input;

    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin, input);
    this->phone_number = input;
    
    std::cout << "Enter darkest secret" << std::endl;
    std::getline(std::cin, input);
    this->darkest_secret = input;

    // std::cin.ignore();
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

std::string	truncate(std::string str) {
	std::string string;

	if (str.length() > 10) {
		string = str.substr(0, 10 - 1) + ".";
		return string;
	}
	else
		return str;

}

void    Contact::print(int index) const {
    std::cout << std::setw(10) << index + 1 << "|"
            << std::setw(10) << truncate(this->first_name) << "|" 
            << std::setw(10) << truncate(this->last_name) << "|" 
            << std::setw(10) << truncate(this->nickname) << std::endl;
}


void    Contact::display() const {
        std::cout << "First name: " << this->getFirstName() << std::endl;
        std::cout << "Last name: " << this->getLastName() << std::endl;
        std::cout << "Nickname: " << this->getNickname() << std::endl;
        std::cout << "Phone number: " << this->getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
}