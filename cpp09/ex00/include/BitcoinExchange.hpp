#pragma once


#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <regex>
#include <iomanip>

class BitcoinExchange {
    private:
        std::map<std::string, std::string>      		data;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange& operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void                                        populateData(const std::string& file);
        void                                        checkInput(const std::string& file);
		void                                        calculateResult(std::string& date, const std::string& value);
        void                                        printMap(const std::multimap<std::string, std::string>& map) const;

        const std::map<std::string, std::string>&   getData() const;

        float                                       isValidValue(const std::string& value);
        float                                       isValidDate(const std::string& date, const std::map<std::string, std::string>& data);
    

};
