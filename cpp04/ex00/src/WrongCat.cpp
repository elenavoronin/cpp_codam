#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>
#include <string>


WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)  {
    std::cout << "WrongCat assignment operator called" << std::endl;
    WrongAnimal::operator=(copy);
    if (this != &copy) 
        type = copy.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout <<"Cat suddenly starts speaking latin" << std::endl;
}
