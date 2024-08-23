#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    Name = "Scav";
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor with parameters called" << std::endl;
    Name = name;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "You have not Hit or Energy Points" << std::endl;
        return ;
    }
    std::cout << "Scav Trap " << Name << " attacks " << target
                << ", causing " << AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}