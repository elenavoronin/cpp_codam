#include <iostream>
#include <string>

int main() 
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPtr = &str;
    std::string& stringRef = str;

    std::cout << "Memory address of string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPtr: " << stringPtr << std::endl;
    std::cout << "Memory address held by stringRef: " << &stringRef << std::endl;

    std::cout << "Value of string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPtr: " << *stringPtr << std::endl;
    std::cout << "Value pointed to by stringRef: " << stringRef << std::endl;

    return 0;
}
