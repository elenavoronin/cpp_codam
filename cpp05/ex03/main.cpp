#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/Bureaucrat.hpp"
#include "./include/Intern.hpp"
#include <iostream>

int main() {
  Intern someIntern;
    Bureaucrat bob("Bob", 45);

    // Test making a ShrubberyCreationForm
    AForm* shrubbery = someIntern.makeForm("shrubbery creation", "Home");
    if (shrubbery) {
        bob.signForm(*shrubbery);
        bob.executeForm(*shrubbery);
        delete shrubbery;
    }

    // Test making a RobotomyRequestForm
    AForm* robotomy = someIntern.makeForm("robotomy request", "Target");
    if (robotomy) {
        bob.signForm(*robotomy);
        bob.executeForm(*robotomy);
        delete robotomy;
    }

    // Test making a PresidentialPardonForm
    AForm* pardon = someIntern.makeForm("presidential pardon", "Criminal");
    if (pardon) {
        bob.signForm(*pardon);
        bob.executeForm(*pardon);
        delete pardon;
    }

    // Test an invalid form name
    AForm* unknown = someIntern.makeForm("unknown form", "NoTarget");
    if (unknown) {
        delete unknown;
    }


    return 0;
}
