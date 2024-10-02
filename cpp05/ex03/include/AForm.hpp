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
        virtual ~AForm();
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
        virtual void action() const = 0;
        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& b);