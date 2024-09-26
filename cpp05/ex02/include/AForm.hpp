#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    protected:
        std::string Name;
        bool        isSigned;
        int         gradeToSign;
        int         gradeToExecute;
    public:
        AForm();
        AForm(std::string Name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm();
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
        virtual void beSigned(const Bureaucrat& f) = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& b);