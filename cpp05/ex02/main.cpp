#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "=== TEST 1: Shrubbery Creation Form ===" << std::endl;
        // Bureaucrat with a grade high enough to sign and execute the form
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrubForm("garden");

        gardener.signForm(shrubForm);  // Should succeed
        gardener.executeForm(shrubForm);  // Should execute and create the shrubbery file

        std::cout << "\n=== TEST 2: Robotomy Request Form ===" << std::endl;
        // Bureaucrat with high enough grade to sign but not execute
        Bureaucrat intern("Intern", 70);
        RobotomyRequestForm robotomyForm("target");

        intern.signForm(robotomyForm);  // Should succeed
        intern.executeForm(robotomyForm);  // Should fail (grade too low for execution)

        Bureaucrat seniorEngineer("Senior Engineer", 40);
        seniorEngineer.executeForm(robotomyForm);  // Should execute the robotomy

        std::cout << "\n=== TEST 3: Presidential Pardon Form ===" << std::endl;
        // Bureaucrat with a grade high enough to sign but too low to execute
        Bureaucrat assistant("Assistant", 24);
        PresidentialPardonForm pardonForm("Prisoner");

        assistant.signForm(pardonForm);  // Should succeed
        assistant.executeForm(pardonForm);  // Should fail (grade too low for execution)

        Bureaucrat president("President", 1);
        president.executeForm(pardonForm);  // Should execute the pardon

        std::cout << "\n=== TEST 4: Form Not Signed ===" << std::endl;
        // Bureaucrat trying to execute a form that wasn't signed
        ShrubberyCreationForm unSignedForm("backyard");
        Bureaucrat junior("Junior", 130);

        junior.executeForm(unSignedForm);  // Should fail because the form is not signed

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
