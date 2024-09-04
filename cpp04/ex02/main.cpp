#include "include/AAnimal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"
#include <iostream>
#include <string>


int main() {
    const int arraySize = 6;
    AAnimal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new Dog();
    }

    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new Cat();
    }

    std::cout << "\nMaking sounds:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\nDeleting animals:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    return 0;
}


