#include "ScavTrap.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

int main( void ) {
    ScavTrap scav("Minny");

   scav.setAttackDamage(2);
   scav.attack("Bonny");
   scav.takeDamage(2);
   scav.beRepaired(1);

   scav.setAttackDamage(3);
   scav.attack("Clive");
   scav.takeDamage(3);
   scav.beRepaired(1);

    std::cout << scav.getHitPoints() << std::endl; 
    std::cout << scav.getEnergyPoints() << std::endl; 

}