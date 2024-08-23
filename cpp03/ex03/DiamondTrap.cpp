#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() :  ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    Name = "Diamond";
    HitPoints = FragTrap::getHitPoints();
    EnergyPoints = ScavTrap::getEnergyPoints();
    AttackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
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

void DiamondTrap::attack(const std::string& target) {
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "You have not Hit or Energy Points" << std::endl;
        return ;
    }
    std::cout << "DiamondTrap " << Name << " attacks " << target
                << ", causing " << AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}