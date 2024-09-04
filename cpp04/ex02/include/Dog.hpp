#pragma once

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
    private:
        Brain   *brain;
    public:
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        virtual ~Dog();
        void makeSound() const override;
};
