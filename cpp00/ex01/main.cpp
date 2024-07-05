#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


int main(int argc, char **argv) {
    while (1)
    {
        if (argc == 1) {
            std::cout << "You can ADD, SEARCH or EXIT" << std::endl;
        }
        else if (argc == 2) {
            Phonebook phonebook;
            std::string command = argv[1];
            if (command == "ADD") {
                phonebook.add(argv[1]);
            }
            else if (command == "SEARCH") {
                phonebook.search(argv[1]);
            }
            else if (command == "EXIT") {
                return 0;
            }
            else
                std::cout << "Wrong command, try ADD, SEARCH or EXIT" << std::endl;
        }
        else
            std::cout << "Wrong number of arguments" << std::endl;
    }
    return 0;
}
