#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>


Bureaucrat::Bureaucrat() : _name("Bob"), _grade(75) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, int grade): _name(Name), _grade(grade) {
    std::cout << "Bureaucrat parameter constructor called" << std::endl;
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &copy)
    {
       this->_grade = copy.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::setGrade(int newGrade) {
    if (newGrade < 1)
        throw GradeTooHighException();
    else if (newGrade > 150)
        throw GradeTooLowException();
    this->_grade = newGrade;
}

void Bureaucrat::increment() {
    this->setGrade(--this->_grade);
}

void Bureaucrat::decrement() {
    this->setGrade(++this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
