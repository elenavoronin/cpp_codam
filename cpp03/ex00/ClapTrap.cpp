#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string Name) {
    std::cout << "Constructor called" << std::endl;
    this->Name = Name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap:: ClapTrap(const ClapTrap& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap:: operator=(const ClapTrap& copy) {
    if (this != &copy)
    {
        this->Name = copy.Name;
        this->HitPoints = copy.HitPoints;
        this->EnergyPoints = copy.EnergyPoints;
        this->AttackDamage = copy.AttackDamage;
    }
    return *this;
}

ClapTrap:: ~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap" << this->Name << "attacks" << target
                << ", causing" << this-> << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {
    setHitPoints(getHitPoints() + amount);
    setEnergyPoints(getEnergyPoints() - 1);
}
