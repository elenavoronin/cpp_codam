#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(2), _gradeToExecute(15) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string Name, const int gradeToSign, const int gradeToExecute) :
    _name(Name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Form parameter constructor called" << std::endl;

}

Form::Form(const Form& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
    *this = copy;
}

Form& Form::operator=(const Form& copy) {
    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
    return this->_name;
}
int Form::getGradeToSign() const {
    return this->_gradeToSign;
}
int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}
bool Form::getIsSigned() const {
    return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& b) {
    if (_isSigned == true)
        throw FormAlreadySignedException();
    if (b.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << " is signed: " << f.getIsSigned() 
    << " Grade to Sign: " << f.getGradeToSign()
    << " Grade to Execute: " << f.getGradeToExecute();
    return os;
}