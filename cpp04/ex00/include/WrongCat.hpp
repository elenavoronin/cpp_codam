#pragma once

#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat& copy);
        WrongCat& operator=(const WrongCat& copy);
        virtual ~WrongCat();
        virtual void makeSound() const override;
};
