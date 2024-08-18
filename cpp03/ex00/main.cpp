#include "ClapTrap.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

int main( void ) {
    ClapTrap trap("Clive");
    ClapTrap trap2("Bonny");

    trap.setAttackDamage(2);
    trap.attack("Bonny");
    trap2.takeDamage(2);
    trap2.beRepaired(1);

    trap2.setAttackDamage(3);
    trap2.attack("Clive");
    trap.takeDamage(3);
    trap.beRepaired(1);

    // std::cout << trap.getHitPoints() << std::endl; 
    // std::cout << trap.getEnergyPoints() << std::endl; 
    // std::cout << trap2.getEnergyPoints() << std::endl; 
    // std::cout << trap2.getHitPoints() << std::endl; 

}