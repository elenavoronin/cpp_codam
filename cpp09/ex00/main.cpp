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
	be.populateInput(file);
	be.populateData("data.csv");
	be.calculateResult();
	be.printMap(be.getResult());


	return 0;
}
