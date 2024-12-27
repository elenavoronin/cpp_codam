#include "../include/ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
    std::cout << "Shrubbery creation form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "Shrubbery creation form parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()), _target(copy._target)  {
    std::cout << "Shrubbery creation form copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    std::cout << "Shrubbery creation form assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery Form destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
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