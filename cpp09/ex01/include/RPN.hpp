#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <stdexcept>

class RPN {
	private:
		std::stack<int>		stak;
		std::string			input;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		~RPN();

		void			populateCheck(const std::string &input);
		void			calculus();
		void			setInput(const std::string &input);
		std::string&	getInput();

		class illegal : public std::exception {
			const char* what() const noexcept override {
                return "Illegal character";
            }
		};

		class wrong : public std::exception {
			const char* what() const noexcept override {
                return "Calculation impossible";
            }
		};

};
