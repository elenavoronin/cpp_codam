#pragma once

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    private:
        Brain   *brain;
    public:
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        virtual ~Dog();
        void makeSound() const override;
};
