#include "HumanB.hpp"
#include <iostream>


HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {
	std::cout << "HumanB constructor called" << std::endl;
}

void	HumanB::attack() {
	std::cout <<name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

HumanB::~HumanB() {
	std::cout << "HumanB denstructor called" << std::endl;
}