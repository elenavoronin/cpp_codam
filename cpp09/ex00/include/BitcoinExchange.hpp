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
        std::map<std::string, int>       input;
        std::map<std::string, int>       data;
        std::map<std::string, int>       resultMap;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange& operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void populateData(const std::string& file);
        void populateInput(const std::string& file);
        bool validateInput() const;
        void printData() const;

        const std::map<std::string, int>& getData() const;
        const std::map<std::string, int>& getInput() const;
        void setInput(std::map<std::string, int>& map);

};


bool isValidDate(const std::string& date);




