#include "Zombie.hpp"
#include <iostream>
#include <string>


int    main(void)
{
    Zombie zombie;
    Zombie *z;

    z = nullptr;
    z = newZombie("Hanky Panky");
    z->announce();
    zombie.setName("Hank");
    zombie.announce();
    delete(z);
}