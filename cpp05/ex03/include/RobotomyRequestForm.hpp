#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
    private:
        const std::string             _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm();
        std::string getTarget() const;
        void action() const override;
};