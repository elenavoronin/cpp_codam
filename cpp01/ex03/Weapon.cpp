#include "weapon.hpp"
#include <iostream>

Weapon::Weapon() {
	std::cout <<"Weapon constructor called" << std::endl;
}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}

Weapon::~Weapon() {
	std::cout << "Weapon destructor called" << std::endl;
}
