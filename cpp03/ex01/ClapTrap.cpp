#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap() {
    std::cout << "Clap Trap default constructor called" << std::endl;
    this->Name = "Default";
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string Name) {
    std::cout << "Clap Trap constructor with parameters called" << std::endl;
    this->Name = Name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->Name = copy.Name;
        this->HitPoints = copy.HitPoints;
        this->EnergyPoints = copy.EnergyPoints;
        this->AttackDamage = copy.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "You have not Hit or Energy Points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << Name << " attacks " << target
                << ", causing " << AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "You have not Hit or Energy Points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << Name << " repairs by " << amount << " energy points!" << std::endl;
   EnergyPoints--;
   HitPoints += amount;
}

void ClapTrap::setAttackDamage(int amount) {
    this->AttackDamage = amount;
}

int ClapTrap::getAttackDamage() {
    return this->AttackDamage;
}
int ClapTrap::getHitPoints() {
    return this->HitPoints;
}
int ClapTrap::getEnergyPoints() {
    return this->EnergyPoints;
}
