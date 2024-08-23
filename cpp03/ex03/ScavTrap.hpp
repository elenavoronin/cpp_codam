#pragma once

#include <string.h>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap& operator=(const ScavTrap &copy);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};