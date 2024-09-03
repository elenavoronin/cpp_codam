#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap() {
    std::cout <<"FragTrap default constructor called" << std::endl;
    Name = "Frag";
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout <<"FragTrap constructor with parameters called" << std::endl;
    Name = name;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout <<"FragTrap copy constructor called" << std::endl;
    *this = copy;
}   

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << "FragTrap assignemnt operator called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Please high five me guys!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "You have not Hit or Energy Points" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << Name << " attacks " << target
                << ", causing " << AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}
