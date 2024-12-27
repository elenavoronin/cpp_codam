#pragma once

#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string Name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        std::string             getName() const;
        int                     getGrade() const;
        void                    setGrade(int grade);
        void                    increment();
        void                    decrement();

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);