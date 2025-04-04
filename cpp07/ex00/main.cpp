#include "template.hpp"


int main()
{
    char a = '5';
    char b = '1';
    std::cout << "initial a: " << a << std::endl; 
    std::cout << "initial b: " << b << std::endl; 
    swap(a, b);
    std::cout << "swapped a: " << a << std::endl; 
    std::cout << "swapped b: " << b << std::endl; 


    int j = min(-15, 25);
    std::cout << "min: " << j << std::endl;

    int i = max(4, 8);
    std::cout << "max:" << i << std::endl;

    return 0;
}