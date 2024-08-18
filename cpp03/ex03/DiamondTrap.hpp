#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string Name;

    public:
        DiamondTrap(std::string Name);
        DiamondTrap(const DiamondTrap& copy);
        DiamondTrap& operator=(const DiamondTrap& copy);
        ~DiamondTrap();
        void whoAmI();
        using ScavTrap::attack;
};
