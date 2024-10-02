#pragma once

#include <string>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;


class Intern {
    private:

    public:
    Intern();
    Intern(const Intern& copy);
    Intern& operator=(const Intern& copy);
    ~Intern();
    AForm* makeForm(const std::string form, const std::string target) const;
};