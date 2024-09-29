#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>

AForm::AForm() : Name("Default AForm"), isSigned(false), gradeToSign(2), gradeToExecute(15) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string Name, int gradeToSign, int gradeToExecute) :
    Name(Name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "AForm parameter constructor called" << std::endl;

}

AForm::AForm(const AForm& copy) {
    std::cout << "AForm copy constructor called" << std::endl;
    *this = copy;
}

AForm& AForm::operator=(const AForm& copy) {
    if (this != &copy)
    {
        this->Name = copy.Name;
        this->isSigned = copy.isSigned;
        this->gradeToExecute = copy.gradeToExecute;
        this->gradeToSign = copy.gradeToSign;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const {
    return this->Name;
}
int AForm::getGradeToSign() const {
    return this->gradeToSign;
}
int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}
bool AForm::getIsSigned() const {
    return this->isSigned;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << " is signed: " << f.getIsSigned() 
    << " Grade to Sign: " << f.getGradeToSign()
    << " Grade to Execute: " << f.getGradeToExecute();
    return os;
}

void AForm::action() const {
    std::cout << "Default action" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (this->isSigned == true)
    {
        if (executor.getGrade() <= this->gradeToExecute)
            this->action();
    }
}