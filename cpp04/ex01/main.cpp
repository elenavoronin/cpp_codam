#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"
#include <iostream>
#include <string>


int main()
{
    Animal *animals[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2)
            animals[i] = new Cat;
        else
            animals[i] = new Dog;
    }

    for (int i = 0; i < 10; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i< 10; i++)
        delete(animals[i]);

}

