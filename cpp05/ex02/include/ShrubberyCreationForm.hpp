#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
    private:
        const std::string                   _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();
        std::string getTarget() const;
        void action() const override;
};