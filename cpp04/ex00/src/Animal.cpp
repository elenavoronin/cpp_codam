#include "../include/Animal.hpp"
#include <iostream>
#include <string>


Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    this->type = "animal";
}

Animal::Animal(const Animal& copy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy)  {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout <<"Animal sounds" << std::endl;
}

std::string Animal::getType() const {
    return type;
}