#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string Name;

    public:
        DiamondTrap();
        DiamondTrap(std::string Name);
        DiamondTrap(const DiamondTrap& copy);
        DiamondTrap& operator=(const DiamondTrap& copy);
        ~DiamondTrap();
        void whoAmI();
        void attack(const std::string& target);
        using ScavTrap::attack;
};
