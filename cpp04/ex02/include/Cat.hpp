#pragma once

#include <string>
#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat: public AAnimal {
    private:
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& copy);
        virtual ~Cat();
        void makeSound() const override;
};
