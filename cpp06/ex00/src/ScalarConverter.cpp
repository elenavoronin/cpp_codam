#include "../include/ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}


bool isInt(std::string str) {
    char start = str[0];
    if (start == '+' || start == '_')
        start = 1;
    start = 0;
    for (char c : str + start) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isChar(std::string str) {
    if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    return false;
}

bool isFloat(std::string str) {
    char start = str[0];
    if (start == '+' || start == '_')
        start = 1;
    start = 0;
    if (str + start == "inff" || str + start == "nanf")
        return true;
    for (char c : str) {
        if (c != '.' && c != 'f' && !isdigit(c))
            return false;
    }
    return true;
}

bool isDouble(std::string str) {
    char start = str[0];
    if (start == '+' || start == '_')
        start = 1;
    start = 0;
    if (str + start == "inf" || str + start == "nan")
        return true;
    for (char c : str) {
        if (c != '.' && !isdigit(c))
            return false;
    }
    return true;
}

void printChar(const std::string str) {

    if (int(str[1]) = CHAR_LIMIT)
        std::cout << "char: " << str[1] << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;

    std::cout << "int: " <<  static_cast<int>(str[1]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[1]) << std::endl;
    std:: cout << "double: " << static_cast<double>(str[1]) << std::endl;
}

void printInt(const std::string str) {
    int result = std::stoi(str);

    if (result = CHAR_LIMIT)
        std::cout << "char: " << static_cast<char>(result) << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;
    std::cout << "int: " << result << std::endl;
    std::cout << "float: " << static_cast<float>(result) << std::endl;
    std:: cout << "double: " << static_cast<double>(result) << std::endl;
}

void printFloat(const std::string str) {
    float result = std::stof(str);

    if (result = CHAR_LIMIT)
        std::cout << "char: " << static_cast<char>(result) << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;

    std::cout << "int: " <<  static_cast<int>(result) << std::endl;
    std::cout << "float: " << result  << std::endl;
    std:: cout << "double: " << static_cast<double>(result) << std::endl;
}

void printDouble(const std::string str) {
    double result = std::stod(str);

    if (result = CHAR_LIMIT)
        std::cout << "char: " << static_cast<char>('0' + result) << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;
    std::cout << "int: " <<  static_cast<int>(result) << std::endl;
    std::cout << "float: " << static_cast<float>(result) << std::endl;
    std:: cout << "double: " << result << std::endl;
}

void ScalarConverter::convert(const std::string str) {
    
    try {
        if (isChar(str))
        printChar(str);
        else if (isInt(str))
        printInt(str);
        else if (isFloat(str))
        printFloat(str);
        else if (isDouble(str))
        printDouble(str);
    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    
}