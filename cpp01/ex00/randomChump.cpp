#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name) {
    Zombie z;
    z.setName(name);
    z.announce();
}