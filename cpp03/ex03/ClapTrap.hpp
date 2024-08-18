#pragma once

#include <string>

class ClapTrap {
    protected:
        std::string Name;
        int         HitPoints;
        int         EnergyPoints;
        int         AttackDamage;

    public:
        ClapTrap(std::string Name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator=(const ClapTrap& copy);
        ~ClapTrap();

        std::string getName();
        int getAttackDamage();
        int getHitPoints();
        int getEnergyPoints();

        void setAttackDamage(int amount);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
