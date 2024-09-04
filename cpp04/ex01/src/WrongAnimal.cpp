#include "../include/WrongAnimal.hpp"
#include <iostream>
#include <string>


WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)  {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout <<"WrongAnimal sounds" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}