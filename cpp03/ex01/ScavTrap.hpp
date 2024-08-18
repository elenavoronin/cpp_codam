#pragma once

#include <string.h>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap& operator=(const ScavTrap &copy);
        ~ScavTrap();
        void guardGate();
};