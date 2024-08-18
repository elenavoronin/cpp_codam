#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout <<"FragTrap constructor called" << std::endl;
    Name = name;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout <<"FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << "FragTrap assignemnt operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Please high five me guys!" << std::endl;
}
