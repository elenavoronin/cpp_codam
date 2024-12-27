#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(2), _gradeToExecute(15) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string Name, const int gradeToSign, const int gradeToExecute) :
    _name(Name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "AForm parameter constructor called" << std::endl;

}

AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy) {
    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const {
    return this->_name;
}
int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}
int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}
bool AForm::getIsSigned() const {
    return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (_isSigned == true)
        throw FormAlreadySignedException();
    if (b.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
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
    if (this->_isSigned == true)
    {
        if (executor.getGrade() <= this->_gradeToExecute)
            this->action();
        else
            throw GradeTooLowException();
    }
    else
        throw FormNotSignedException();

}