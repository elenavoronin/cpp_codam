#include "../include/Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(const Brain& copy) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &copy)
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(const std::string idea, int index) {
    this->ideas[index] = idea;
}

std::string Brain::getIdeas(int index) const {
    return this->ideas[index];
}