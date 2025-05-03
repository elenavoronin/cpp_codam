#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {
	*this = copy;
}

RPN& RPN::operator=(const RPN& copy) {
	if (this != &copy){
		this->stak = copy.stak;
		this->input = copy.input;
	}
	return *this;
}

RPN::~RPN() {}

void	RPN::populateCheck(const std::string &input) {
	for (unsigned long i = 0; i < input.size(); i++) {
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != ' ') {
			std::cout << "input: " << input[i] << std::endl; 	
			throw illegal();
		}
	}
	setInput(input);
}

void RPN::setInput(const std::string &input) {
	this->input = input;
}

std::string&	RPN::getInput() {
	return this->input;
}

void RPN::calculus() {
	std::string input = getInput();
	unsigned long i = 0;
	int nr1 = 0;
	int nr2 = 0;
	int res = 0;
	while (i < input.size()) {
		if (isdigit(input[i])) {
			stak.push(input[i] - 48);
		}
		else if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-') {
			if (stak.size() >= 2) {
				nr2 = stak.top();
				stak.pop();
				nr1 = stak.top();
				stak.pop();
				if (input[i] == '+')
					res = nr1 + nr2;
				else if (input[i] == '-')
					res = nr1 - nr2;
				else if (input[i] == '*')
					res = nr1 * nr2;
				else if (input[i] == '/')
					res = nr1 / nr2;
				if (res)
					stak.push(res);
				else
					throw wrong();
			}
			else
				throw wrong();
		}
		i++;
	}
	if (stak.size() == 1) {
		std::cout << "Result: " << stak.top() << std::endl;
		return ;
	}
	else
		throw wrong();
}
