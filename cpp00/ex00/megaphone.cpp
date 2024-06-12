
#include <iostream>
#include <string>
#include <cctype>

void toUppercaseAndPrint(char *str) 
{
    int i;

    i = 0;
    while(str[i])
    {
        std::cout << (char)std::toupper(str[i]);
        i++;
    }
}

int main(int argc, char **argv) 
{
    int i;

    i = 1;
    if (argc == 1) 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        while (argv[i])
        {
            toUppercaseAndPrint(argv[i]);
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}