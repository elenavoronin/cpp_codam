#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string Name;
        bool        isSigned;
        int         gradeToSign;
        int         gradeToExecute;
    public:
        Form();
        Form(std::string Name, int gradeToSign, int gradeToExecute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
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
        void beSigned(const Bureaucrat& f);

};

std::ostream& operator<<(std::ostream& os, const Form& b);