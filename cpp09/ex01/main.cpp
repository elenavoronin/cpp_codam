#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc !=2)
		return -1;
	RPN rpn;
	std::string input = argv[1];
	std::cout << input << std::endl;
	try {
		rpn.populateCheck(input);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}
	try {
		rpn.calculus();
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
