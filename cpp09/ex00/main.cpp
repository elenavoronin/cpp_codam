#include "BitcoinExchange.hpp"
\
int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Please input a file" << std::endl;
		return -1;
	}

	BitcoinExchange be;
	const std::string &file = argv[1];
	be.populateData("data.csv");
	try {
		be.checkInput(file);
	}
	catch (std::exception &e) {
		std::cerr << "File error: " << e.what() << std::endl;
	}


	return 0;
}
