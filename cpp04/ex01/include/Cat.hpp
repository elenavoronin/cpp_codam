#pragma once

#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal {
    private:
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& copy);
        virtual ~Cat();
        void makeSound() const override;
};
