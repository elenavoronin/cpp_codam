#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


int main() {
    while (1)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        Phonebook phonebook;
        std::string command;
        phonebook.setlast(0);
        phonebook.setindex(0);
        std::getline(std::cin, command);
        if (command == "ADD") {
            phonebook.add();
            phonebook.setlast(phonebook.getlast() + 1);
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
