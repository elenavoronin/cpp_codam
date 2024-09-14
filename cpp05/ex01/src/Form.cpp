#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>

Form::Form() : Name("Default Form"), isSigned(false), gradeToSign(2), gradeToExecute(15) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string Name, int gradeToSign, int gradeToExecute) :
    Name(Name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "Form parameter constructor called" << std::endl;

}

Form::Form(const Form& copy) {
    std::cout << "Form copy constructor called" << std::endl;
    *this = copy;
}

Form& Form::operator=(const Form& copy) {
    if (this != &copy)
    {
        this->Name = copy.Name;
        this->isSigned = copy.isSigned;
        this->gradeToExecute = copy.gradeToExecute;
        this->gradeToSign = copy.gradeToSign;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
    return this->Name;
}
int Form::getGradeToSign() const {
    return this->gradeToSign;
}
int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}
bool Form::getIsSigned() const {
    return this->isSigned;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << " is signed: " << f.getIsSigned() 
    << " Grade to Sign: " << f.getGradeToSign()
    << " Grade to Execute: " << f.getGradeToExecute();
    return os;
}