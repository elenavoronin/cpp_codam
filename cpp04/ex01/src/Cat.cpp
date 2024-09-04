#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include <iostream>
#include <string>


Cat::Cat() : Animal() {
    std::cout << "Default Cat constructor called" << std::endl;
    this->type = "cat";
    this->brain = new Brain;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
    type = copy.type;
    brain = new Brain(*copy.brain); // deep copy
}

Cat& Cat::operator=(const Cat& copy)  {
    std::cout << "Cat assignment operator called" << std::endl;
    if(this != &copy) {
        Animal::operator=(copy);
        delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete(this->brain);
}

void Cat::makeSound() const {
    std::cout <<"Meoooooooooooooooooooooooow" << std::endl;
}
