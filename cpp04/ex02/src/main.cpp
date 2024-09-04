#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
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