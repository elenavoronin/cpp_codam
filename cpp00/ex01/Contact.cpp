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
    std::cin >> contact.first_name;

    std::cout << "Enter last name" << std::endl;
    std::cin >> contact.last_name;

    std::cout << "Enter nickname" << std::endl;
    std::cin >> contact.nickname;

    std::cout << "Enter phone number" << std::endl;
    std::cin >> contact.phone_number;

    std::cout << "Enter darkest secret" << std::endl;
    std::cin >> contact.darkest_secret;
    std::cin.ignore();

    *this = contact;
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

std::string	Contact::truncate(std::string str) {
	std::string string;
	string = str.substr(0, 10 - 1) + ".";
	return string;

}

void    Contact::display(int index) const {
	if (this->first_name.length() > 10) {
		truncate(this->first_name);
	}
	if (this->last_name.length() > 10 ){
		this->last_name.substr(0, 10 - 1) + ".";
	}
	if (this->nickname.length() > 10) {
		this->nickname.substr(0, 10 - 1) + ".";
	}
    std::cout << std::setw(10) << "index" << "|" 
            << std::setw(10) << "first name" <<  "|" 
            << std::setw(10) << "last name" << "|" 
            << std::setw (10) << "nickname" << std::endl;
    std::cout << std::setw(10) << index << "|"
            << std::setw(10) << this->first_name << "|" 
            << std::setw(10) << this->last_name << "|" 
            << std::setw(10) << this->nickname << std::endl;
}
