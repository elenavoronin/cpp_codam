#include "../include/ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
    std::cout << "Shrubbery creation form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm() {
    std::cout << "Shrubbery creation form parameter constructor called" << std::endl;
    this->target = target;
    this->gradeToSign = 145;
    this->gradeToExecute = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm() {
    std::cout << "Shrubbery creation form copy constructor called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) : AForm() {
    std::cout << "Shrubbery creation form assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->target = copy.target;   
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery Form destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}