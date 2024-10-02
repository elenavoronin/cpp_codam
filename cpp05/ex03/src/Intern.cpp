#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
#include <map>


Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
    std::cout << "Intern assignment operator called" << std::endl;
    (void)copy;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const {
    enum FormType { SHRUBBERY = 1, ROBOTOMY, PRESIDENTIAL };
    FormType formType;
    if (formName == "shrubbery creation") {
        formType = SHRUBBERY;
    }
    else if (formName == "robotomy request") {
        formType = ROBOTOMY;
    }
    else if (formName == "presidential pardon") {
        formType = PRESIDENTIAL;
    }
    else {
        std::cout << "This form type is not supported" << std::endl;
        return nullptr;
    }
    switch (formType) {
        case 1: {
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        }
        case 2: {
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        }
        case 3: {
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);       
        }
        default: {
            std::cout << "This form type is not supported" << std::endl;
            return nullptr;
        }
    }
}