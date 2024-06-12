#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>


class Zombie
{
private:
    std::string  name;

public:
    Zombie();
    void announce(void);
    void setName(const std::string& newName) {
        name = newName;
    }
    std::string getName(void) const {
        return this->name;
    }
    ~Zombie();
};


void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif