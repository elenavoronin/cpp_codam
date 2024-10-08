#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <stdio.h>
#include <string>


int main() {
    Phonebook phonebook;
	phonebook.setcount(0);
	phonebook.setoldest(0);
    while (1)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        std::string command;
        std::getline(std::cin, command);
        if (command == "ADD") {
            Contact contact;
            contact.setContact();
            phonebook.add(contact);
		}
        else if (command == "SEARCH") {
            phonebook.search();
        }
        else if (command == "EXIT") {
            break ;
        }
        else if (std::cin.eof()) {
            break ;
        }
        else {
            std::cout << "Wrong command" << std::endl;
        }
    }
    return 0;
}
