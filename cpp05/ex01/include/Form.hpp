#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string               _name;
        bool                            _isSigned;
        const int                       _gradeToSign;
        const int                       _gradeToExecute;
    public:
        Form();
        Form(const std::string Name, const int gradeToSign, const int gradeToExecute);
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

        class FormAlreadySignedException:  public std::exception {
            public:

                const char* what() const throw() {
                    return "the form has already been signed";
                }
        };
        
        void beSigned(const Bureaucrat& f);

};

std::ostream& operator<<(std::ostream& os, const Form& b);