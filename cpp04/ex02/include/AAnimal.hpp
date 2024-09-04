#pragma once

#include <string>

class AAnimal {
    protected:
        std::string type;
    
    public:
        AAnimal();
        AAnimal(const AAnimal& copy);
        AAnimal& operator=(const AAnimal& copy);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        std::string getType() const;
};
