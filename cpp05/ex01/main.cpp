#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        Bureaucrat b1("John", 50);
        Form f1("Form1", 45, 30);
        b1.signForm(f1);

        Bureaucrat b2("Jane", 20);
        Form f2("Form2", 15, 10);
        b2.signForm(f2);
        
        Bureaucrat b3("Alice", 5);
        Form f3("Form3", 4, 2);
        b3.signForm(f3);

        // This should fail
        Bureaucrat b4("Bob", 1);
        Form f4("Form4", 50, 30);
        b4.signForm(f4);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}