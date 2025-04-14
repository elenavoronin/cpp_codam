#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy) {
        this->input = copy.input;
        this->data = copy.data;
        this->result = copy.result;
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
    std::multimap<std::string, std::string> input;
    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open input file: " + file);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string key;
        std::string value;
        if (line.empty())
			continue;
		
        if (std::getline(lineStream, key, '|') && lineStream >> value) {
			key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			input.insert(std::make_pair(key, value));
        }
        else {
			input.insert(std::make_pair("Error: " + line, ": bad input"));
		}
			
    }
    inputFile.close();
	printMap(input);
    setInput(input);
}


void BitcoinExchange::printMap(const std::multimap<std::string, std::string>& map) const {
	for (auto it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

}

const std::map<std::string, std::string>& BitcoinExchange::getData() const {
	return this->data;
}

const std::multimap<std::string, std::string>& BitcoinExchange::getInput() const {
	return this->input;
}

const std::multimap<std::string, std::string>& BitcoinExchange::getResult() const {
    return this->result;
}

void BitcoinExchange::setInput(std::multimap<std::string, std::string>& map) {
    this->input = map;
}

bool isValidDate(const std::string& date) {
    // Defined the regex for Year-Month-Day format
    std::regex dateRegex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    return std::regex_match(date, dateRegex);

}

bool isValidValue(const std::string& value) {
    std::regex valueRegex(R"(^\d+(\.\d+)?$)");
    if (!std::regex_match(value, valueRegex))
		return false;
	float numericValue = std::stof(value);
	return numericValue >= 0 && numericValue <= 1000;
}

std::string findNextDate(const std::string &date, const std::map<std::string, std::string> &data) {
	std::string new_date;

	

	return new_date;
}

void BitcoinExchange::calculateResult() {
	std::map<std::string, std::string> data = getData();
	std::multimap<std::string, std::string> input = getInput();
	std::multimap<std::string, std::string> res;
	for (auto it = input.begin(); it != input.end(); it++) {
		std::string date = it->first;
		std::string value = it->second;
		if (!isValidDate(date) || !isValidValue(value)) {
			res.insert(std::make_pair("Error: ", "Bad input"));
		}
		else {
			float rate;
            auto it = data.find(date);
            if (it != data.end()) {
                rate = std::stof(it->second);
            } else {
                date = findNextDate(date, data);
				it = data.find(date);
				rate = std::stof(it->second);
            }
			res.insert(std::make_pair(date, std::to_string(std::stof(value) * rate)));
		}
	}

}
