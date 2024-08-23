#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};