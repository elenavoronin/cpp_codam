#include "ScalarConverter.hpp"


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
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (char c : str.substr(i)) {
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
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    std::string string = str.substr(i);
    if (string.compare("inff") || string.compare("nanf"))
        return true;
    for (char c : str) {
        if (c != '.' && c != 'f' && !isdigit(c))
            return false;
    }
    return true;
}

bool isDouble(std::string str) {
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    std::string string = str.substr(i);
    if (string.compare("inf") || string.compare("nan"))
        return true;
    for (char c : str) {
        if (c != '.' && !isdigit(c))
            return false;
    }
    return true;
}

bool checkLimit(void *data) {
    int value = *static_cast<int*>(data);
    bool found = false;
    for (unsigned long i = 0; i < sizeof(CHAR_LIMIT) / sizeof(CHAR_LIMIT[0]); i++) {
        if (value == CHAR_LIMIT[i]) {
            return true;
        }
    }
    return found;
}

void printChar(const std::string str) {
    char c = str[1];
    if (!checkLimit(&c) && c > 0)
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;
    std::cout << "int: " <<  static_cast<int>(str[1]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[1]) << std::endl;
    std:: cout << "double: " << static_cast<double>(str[1]) << std::endl;
}

void printInt(const std::string str) {
    int result = std::stoi(str);
    if (!checkLimit(&result) && result < 0 && result > 127)
        std::cout << "char: " << static_cast<char>(result) << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;
    std::cout << "int: " << result << std::endl;
    std::cout << "float: " << static_cast<float>(result) << std::endl;
    std:: cout << "double: " << static_cast<double>(result) << std::endl;
}

void printFloat(const std::string str) {
    float result = std::stof(str);
    if (checkLimit(&result) && result > 0 && result < 127 && str.compare("nanf") && str.compare("+inff") && str.compare("-inff"))
        std::cout << "char: " << static_cast<char>(result) << std::endl;
    else
        std::cout << "char: not convertible" << std::endl;

    if (static_cast<int>(result) < INT_MAX && static_cast<int>(result) > INT_MIN)
        std::cout << "int: " <<  static_cast<int>(result) << std::endl;
    else
        std::cout << "int: " <<  "not convertible" << std::endl;
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
	}
    else
	{
		std::cout << "float: " << str << std::endl;
        std:: cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(result) << std::endl;
	}
}


void printDouble(const std::string str) {
    double result = std::stod(str);

    if (!checkLimit(&result) && str.compare("nan") && str.compare("+inf") && str.compare("-inf"))
        std::cout << "char: " << static_cast<char>('0' + result) << std::endl;
    else
        std::cout << "char: not convertable" << std::endl;
    if (static_cast<int>(result) < INT_MAX && static_cast<int>(result) > INT_MIN)
        std::cout << "int: " <<  static_cast<int>(result) << std::endl;
    else
        std::cout << "int: " <<  "not convertible" << std::endl;
    if (str == "nan" || str== "-inf" || str == "+inf")
	{
        std::cout << "float: " << str << "f" << std::endl;
		std:: cout << "double: " << str << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(result) << std::endl;
		std:: cout << "double: " << result << std::endl;
	}
}


void ScalarConverter::convert(const std::string str) {
    std::function<void(const std::string&)> func;
    
    try {
        if (isChar(str))
            func = printChar;
        else if (isInt(str))
            func = printInt;
        else if (isFloat(str))
            func = printFloat;
        else if (isDouble(str))
            func = printDouble;
        else {
            throw std::invalid_argument("Invalid argument");
        }
        func(str);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
