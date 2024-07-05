#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl() {
    std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl() {
    std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn't be asking for more" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

int get_level(std::string level) {
    if (level == "DEBUG")
      return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    else
        return -1;
}

void    Harl::complain (std::string level) {

    void (Harl::*levelarr[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    int index = get_level(level);
    switch(index) {
        case 0:
            (this->*levelarr[0])();
             // Fall through
        case 1:
            (this->*levelarr[1])();
             // Fall through
        case 2:
            (this->*levelarr[2])();
             // Fall through
        case 3:
            (this->*levelarr[3])();
            break;
        default:
            std::cout << "[No clue what Harl is saying]" << std::endl;
            break;
    }
}
