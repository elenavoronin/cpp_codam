#pragma once


#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <regex>

class BitcoinExchange {
    private:
        std::multimap<std::string, std::string>      	input;
        std::map<std::string, std::string>      		data;
        std::multimap<std::string, std::string> 		result;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange& operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void populateData(const std::string& file);
        void populateInput(const std::string& file);
        bool validateInput() const;
		void calculateResult();
        void printMap(const std::multimap<std::string, std::string>& map) const;

        const std::map<std::string, std::string>& getData() const;
        const std::multimap<std::string, std::string>& getInput() const;
        const std::multimap<std::string, std::string>& getResult() const;
        void setInput(std::multimap<std::string, std::string>& map);


};

bool isValidValue(const std::string& value);
bool isValidDate(const std::string& date);
std::string findNextDate(const std::string &date, const std::map<std::string, std::string> &data);
