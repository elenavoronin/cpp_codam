#include "ClapTrap.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

int main( void ) {
    ClapTrap trap("Clive");
    ClapTrap trap2("Bonny");

    trap.attack("Bonny");
    trap.takeDamage(2);
    trap.beRepaired(1);


}