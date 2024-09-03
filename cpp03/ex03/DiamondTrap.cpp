#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() :  ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    Name = "Diamond";
    HitPoints = FragTrap::getHitPoints();
    EnergyPoints = ScavTrap::getEnergyPoints();
    AttackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
    std::cout << "DiamondTrap constructor with parameters called" << std::endl;
    this->Name = name;
    this->HitPoints = FragTrap::getHitPoints();
    this->EnergyPoints = ScavTrap::getEnergyPoints();
    this->AttackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        Name = copy.Name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << Name << ", ClapTrap name: " << ClapTrap::Name << std::endl;
}
