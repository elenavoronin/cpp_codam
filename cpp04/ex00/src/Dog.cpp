#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include <iostream>
#include <string>


Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy)  {
    std::cout << "Dog assignment operator called" << std::endl;
    Animal::operator=(copy);
    if (this != &copy) 
        type = copy.type;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout <<"Woof woof woooooof" << std::endl;
}
