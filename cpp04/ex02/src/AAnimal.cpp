#include "../include/AAnimal.hpp"
#include <iostream>
#include <string>


AAnimal::AAnimal() {
    std::cout << "AAnimal constructor called" << std::endl;
    this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& copy) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)  {
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

// void AAnimal::makeSound() const {
//     std::cout <<"AAnimal sounds" << std::endl;
// }

std::string AAnimal::getType() const {
    return type;
}