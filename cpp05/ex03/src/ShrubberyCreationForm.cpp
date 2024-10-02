#include "../include/ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

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

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
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

void ShrubberyCreationForm::action() const {
    std::ofstream newFile(this->getTarget() + "_shrubbery");
    if (newFile.is_open()) {
        newFile << "       ^\n";
        newFile << "      ^^^\n";
        newFile << "     ^^^^^\n";
        newFile << "    ^^^^^^^\n";
        newFile << "   ^^^^^^^^^\n";
        newFile << "  ^^^^^^^^^^^\n";
        newFile << "      |||\n";
    }
    else
        std::cout << "Could not open file" << std::endl;
    newFile.close();
}