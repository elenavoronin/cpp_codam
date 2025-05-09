#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy) {
        this->data = copy.data;
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
        std::string value;
    
        if (std::getline(lineStream, key, ',') && lineStream >> value) {
            data[key] = value;
        }
        else
            continue ;
    }
    inputFile.close();
}

void BitcoinExchange::checkInput(const std::string& file) {
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
            if (key == "date" && value == "value")
                continue;
			key.erase(std::find(key.begin(), key.end(), ' '), key.end());
			value.erase(std::find(value.begin(), value.end(), ' '), value.end());
            calculateResult(key, value);
        }
        else {
            std::cout << "Error: bad Input => " << key << " " << value << std::endl;
        }
    }
    inputFile.close();
}


void BitcoinExchange::printMap(const std::multimap<std::string, std::string>& map) const {
	for (auto it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

}

const std::map<std::string, std::string>& BitcoinExchange::getData() const {
	return this->data;
}

float BitcoinExchange::isValidDate(const std::string& date, const std::map<std::string, std::string>& data) {
    std::regex dateRegex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
	if (!std::regex_match(date, dateRegex)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }
	
	std::tm     tm{};
    std::string rate;
    float       finalRate = -1;
    try {
        tm.tm_year = std::stoi(date.substr(0, 4)) - 1900;
        tm.tm_mon = std::stoi(date.substr(5, 2)) - 1;
        tm.tm_mday = std::stoi(date.substr(8,2));
    }
    catch (std::exception &e) {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }
    std::tm tmCheck{};
    tmCheck.tm_year = tm.tm_year;
    tmCheck.tm_mon = tm.tm_mon;
    tmCheck.tm_mday = tm.tm_mday;
    if (std::mktime(&tm) == -1 || tmCheck.tm_year != tm.tm_year || tmCheck.tm_mon != tm.tm_mon || tmCheck.tm_mday!= tm.tm_mday) {
        std::cout << "Error: invalid date => " << date << std::endl;
        return -1;
    }
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->first <= date) {
            rate = it->second;
        }
    }
    try
    {
        finalRate = std::stof(rate);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }
    
    return finalRate;
}

float BitcoinExchange::isValidValue(const std::string& value) {
    std::regex valueRegex(R"(^(?:\d{1,3}(?:\.\d+)?|1000(?:\.0+)?)$)");
	if (!std::regex_match(value, valueRegex)) {
        std::cout << "Error: not a valid number => " << value << std::endl;
        return -1;
    }
	float nr = 0;
    try {
        nr = std::stof(value);
    }
    catch (std::exception &e) {
        std::cout << "Error: not a valid number => " << value << std::endl;
        return -1;
    }
    if (nr < 0) {
        std::cout << "Error: not a positive number => " << value << std::endl;
        return -1;
    }
    if (nr > 1000)
    {
        std::cout << "Error: too large a number => " << value << std::endl;
        return -1;
    }
	return nr;
}

void BitcoinExchange::calculateResult(std::string& date, const std::string& value) {
	std::map<std::string, std::string> data = getData();
    float res = 0.0;
    float nr = isValidValue(value);
    if (nr == -1)
        return ;
    float rate = isValidDate(date, data);
    if (rate == -1)
        return ;
    res = rate * nr;
    std::cout << date << " => " << value << " = "  << std::fixed << std::setprecision(2) << res << std::endl;
}
