#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) : type(type) {
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
