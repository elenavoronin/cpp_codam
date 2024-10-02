#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        std::string Name;
        int         grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string Name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();

        class GradeTooHighException:  public std::exception {
            public:
                const char* what() const throw() {
                    return "grade too high";
                }
        };
        class GradeTooLowException:  public std::exception {
            public:
                const char* what() const throw() {
                    return "grade too low";
                }
        };
        void signForm(AForm& form);
        void executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);