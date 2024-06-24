#include "HumanA.hpp"
#include <iostream>


HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	std::cout << "HumanA constructor called" << std::endl;
}

void	HumanA::attack() {
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA denstructor called" << std::endl;
}
