#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include <iostream>
#include <string>


// int main()
// {
//     Animal Animal;
//     Dog dog;
//     Cat cat;

//     std::cout << "Generic Animal sound: ";
//     Animal.makeSound();

//     std::cout << "Dog sound: ";
//     dog.makeSound();

//     std::cout << "Cat sound: ";
//     cat.makeSound();

//     std::cout << "Animal type: " << Animal.getType() << std::endl;
//     std::cout << "Dog type: " << dog.getType() << std::endl;
//     std::cout << "Cat type: " << cat.getType() << std::endl;


// }


int main()
{
    const WrongAnimal* meta = new WrongAnimal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete(meta);
    delete(j);
    delete(i);
    return 0;
}