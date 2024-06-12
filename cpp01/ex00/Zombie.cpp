#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(/* args */) {
    std::cout << "Zombie constructor called" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destructor called" << std::endl;
}
