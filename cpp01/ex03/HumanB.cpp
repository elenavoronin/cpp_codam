#include "HumanB.hpp"
#include <iostream>


HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
	std::cout << "HumanB constructor called" << std::endl;
}

void	HumanB::attack() {
	std::cout <<name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon) {
	if (&weapon != nullptr)
		this->weapon = &weapon;
	else
		return ;
}

HumanB::~HumanB() {
	std::cout << "HumanB denstructor called" << std::endl;
}
