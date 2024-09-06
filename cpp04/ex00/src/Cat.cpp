#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include <iostream>
#include <string>


Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy)  {
    std::cout << "Cat assignment operator called" << std::endl;
    Animal::operator=(copy);
    if (this != &copy) 
        type = copy.type;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout <<"Meoooooooooooooooooooooooow" << std::endl;
}
