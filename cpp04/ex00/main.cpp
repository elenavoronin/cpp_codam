#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>


int main()
{
    Animal Animal;
    Dog dog;
    Cat cat;

    // Calling makeSound() on each object
    std::cout << "Generic Animal sound: ";
    Animal.makeSound();

    std::cout << "Dog sound: ";
    dog.makeSound();

    std::cout << "Cat sound: ";
    cat.makeSound();

    std::cout << "Animal type: " << Animal.getType() << std::endl;
    std::cout << "Dog type: " << dog.getType() << std::endl;
    std::cout << "Cat type: " << cat.getType() << std::endl;


}