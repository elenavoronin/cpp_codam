#include "DiamondTrap.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Sparkly little devil");

    diamond.attack("target");
    diamond.takeDamage(5);
    diamond.beRepaired(3);
    diamond.whoAmI();


    std::cout << diamond.getHitPoints() << std::endl; 
    std::cout << diamond.getEnergyPoints() << std::endl; 
    return 0;
}
