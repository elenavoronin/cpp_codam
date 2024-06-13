#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name) {
    newZombie(name)->announce();
}
