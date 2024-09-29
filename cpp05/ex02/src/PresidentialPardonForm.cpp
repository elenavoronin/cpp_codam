#include "../include/PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
    std::cout << "Presidential pardon form default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm() {
    std::cout << "Presidential pardon form parameter constructor called" << std::endl;
    this->target = target;
    this->gradeToSign = 25;
    this->gradeToExecute = 5;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm() {
    std::cout << "Presidential pardon form copy constructor called" << std::endl;
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    std::cout << "Presidential pardon form assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->target = copy.target;   
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential pardon Form destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::action() const {
    std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}