#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>


Bureaucrat::Bureaucrat() : Name("Bob"), grade(75) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int grade): Name(Name), grade(grade) {
    std::cout << "Bureaucrat parameter constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->Name = copy.getName();
        this->grade = copy.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return this->Name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::increment() {
    if (grade == (this->getGrade() - 1) < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement() {
    if (grade == (this->getGrade() + 1) > 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}


void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cout << this->getName() << " couldn't sign " 
        << form.getName() << ", because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
    if (grade <= form.getGradeToExecute())
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    else
        std::cout << "Execution failed, grade for execution too low" << std::endl;
}
