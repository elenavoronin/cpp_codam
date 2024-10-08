#pragma once

#include <string>

class Animal {
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};
