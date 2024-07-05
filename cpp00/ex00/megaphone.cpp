
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) 
{
    int i;

    i = 1;
    if (argc == 1) 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        for (int i = 1; i < argc; i++) {
            std::string str = argv[i];
            for (char&c : str) {
               c = std::toupper(c);
            }
            std::cout << str << " ";
    }
    }
    std::cout << std::endl;
    return (0);
}