#include "Zombie.hpp"
#include <iostream>
#include <string>


int    main(void)
{
    Zombie zombie;
    Zombie *z;

    z = nullptr;
    zombie.setName("Hank");
    zombie.announce();
    z = newZombie("Hanky Panky");
    z->announce();
    delete(z);
}