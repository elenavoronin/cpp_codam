#include "FragTrap.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

int main( void ) {
    FragTrap frag("Boris");

   frag.setAttackDamage(2);
   frag.attack("Many");
   frag.takeDamage(2);
   frag.beRepaired(1);

   frag.setAttackDamage(3);
   frag.attack("Hany");
   frag.takeDamage(3);
   frag.beRepaired(1);

   frag.highFivesGuys();

    std::cout << frag.getHitPoints() << std::endl; 
    std::cout << frag.getEnergyPoints() << std::endl; 

}