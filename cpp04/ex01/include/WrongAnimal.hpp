#pragma once

#include <string>


class WrongAnimal {
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
};