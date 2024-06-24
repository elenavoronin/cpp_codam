#include "Zombie.hpp"
#include <iostream>
#include <string>


int    main(void)
{
	
	Zombie* horde = zombieHorde(10, "franky");
	for(int i = 0; i < 10; i++) {
		horde[i].announce();
	}
    delete[] horde;
}
