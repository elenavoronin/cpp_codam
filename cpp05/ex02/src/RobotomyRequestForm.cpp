#include "../include/RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm() {
    std::cout << "Robotomy request form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm() {
    std::cout << "Robotomy request form parameter constructor called" << std::endl;
    this->target = target;
    this->gradeToSign = 72;
    this->gradeToExecute = 45;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm() {
    std::cout << "Robotomy request form copy constructor called" << std::endl;
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    std::cout << "Robotomy request form assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->target = copy.target;   
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy Form destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->target;
}

void RobotomyRequestForm::action() const {
    std::cout << "Drilling noise" << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->getTarget() << "has been robotomized successfully" << std::endl;
    else
        std::cout << this->getTarget() << "robotomy failed" << std::endl;
}