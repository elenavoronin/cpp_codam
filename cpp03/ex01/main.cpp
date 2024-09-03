#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main( void ) {
    ScavTrap scav("Minny");
    ScavTrap trap(scav);

   scav.setAttackDamage(2);
   scav.attack("Bonny");
   scav.takeDamage(2);
   scav.beRepaired(1);

   scav.setAttackDamage(3);
   scav.attack("Clive");
   scav.takeDamage(3);
   scav.beRepaired(1);

   scav.guardGate();

    std::cout << scav.getHitPoints() << std::endl; 
    std::cout << scav.getEnergyPoints() << std::endl; 
    std::cout << trap.getHitPoints() << std::endl; 
    std::cout << trap.getEnergyPoints() << std::endl; 
    

}