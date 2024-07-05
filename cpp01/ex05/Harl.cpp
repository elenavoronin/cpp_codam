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
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn't be asking for more" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void    Harl::complain (std::string level) {
    void (Harl::*levelarr[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    std::string options[4] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++) {
        if (options[i] == level) {
            (this->*levelarr[i])();
            return; 
        }
    }
}
