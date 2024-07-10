#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


int main() {
    Phonebook phonebook;
    while (1)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        std::string command;
        phonebook.setcount(0);
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
        else {
            std::cout << "Wrong command" << std::endl;
        }
    }
    return 0;
}
