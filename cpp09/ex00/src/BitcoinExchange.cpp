#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy) {
        this->input = copy.input;
        this->data = copy.data;
        this->resultMap = copy.resultMap;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::populateData(const std::string& file) {
    std::ifstream inputFile(file);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open input file: " + file);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string key;
        int value;
    
        if (std::getline(lineStream, key, ',') && lineStream >> value) {
            data[key] = value;
        }
        else
            continue ;
    }
    inputFile.close();
}

void BitcoinExchange::populateInput(const std::string& file) {
    std::ifstream inputFile(file);
    std::map<std::string, int> input;
    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open input file: " + file);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string key;
        int value;

        if (key.back() == ' ')
            key.substr(0, key.size() -1);
        if (std::getline(lineStream, key, '|') && lineStream >> value) {
            input[key] = value;
        }
        else
            continue ;
    }
    inputFile.close();
    setInput(input);
}

bool isValidDate(const std::string& date) {
    // Defined the regex for Year-Month-Day format
    std::regex dateRegex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    return std::regex_match(date, dateRegex);
}

void BitcoinExchange::printData() const {

}

const std::map<std::string, int>& BitcoinExchange::getData() const {

}

const std::map<std::string, int>& BitcoinExchange::getInput() const {

}

void BitcoinExchange::setInput(std::map<std::string, int>& map) {
    this->input = map;
}

bool isValidDate(const std::string& date) {
    // Defined the regex for Year-Month-Day format
    std::regex dateRegex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    return std::regex_match(date, dateRegex);
}