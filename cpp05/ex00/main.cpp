#include "./include/Bureaucrat.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        Bureaucrat b1("John", 151); // Will throw GradeTooLowException
        std::cout << b1 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b2("Jane", 1);
        std::cout << b2 << std::endl;
        b2.increment(); // Will throw GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b("Alice", 42);
        std::cout << b << std::endl;
        Bureaucrat c("Bob", 151);
        std::cout << c << std::endl;  // Will throw an exception
        c.decrement();
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    }
    return 0;
}
