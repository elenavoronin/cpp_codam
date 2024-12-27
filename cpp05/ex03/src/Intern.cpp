#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
#include <map>
#include <functional>


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
    static const std::map<std::string, std::function<AForm*(const std::string&)>> formFactory = {
        {"shrubbery creation", [](const std::string& target) { return new ShrubberyCreationForm(target); }},
        {"robotomy request", [](const std::string& target) { return new RobotomyRequestForm(target); }},
        {"presidential pardon", [](const std::string& target) { return new PresidentialPardonForm(target); }}
    };

    std::map<std::string, std::function<AForm*(const std::string&)>>::const_iterator it = formFactory.find(formName);

    if (it != formFactory.end()) {
        std::cout << "Intern creates " << formName << std::endl;
        return it->second(target); // Call the corresponding lambda to create the form
    }

    std::cout << "This form type is not supported" << std::endl;
    return nullptr;
}   