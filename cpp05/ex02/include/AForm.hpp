#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    protected:
        const std::string               _name;
        bool                            _isSigned;
        const int                       _gradeToSign;
        const int                       _gradeToExecute;
    public:
        AForm();
        AForm(const std::string Name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm();
        std::string                     getName() const;
        int                             getGradeToSign() const;
        int                             getGradeToExecute() const;
        bool                            getIsSigned() const;

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

    class FormNotSignedException: public std::exception {
        public:
        const char* what() const throw() {
            return "the form is not signed";
            }
        };

        
        void beSigned(const Bureaucrat& f);
        virtual void action() const = 0;
        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& b);