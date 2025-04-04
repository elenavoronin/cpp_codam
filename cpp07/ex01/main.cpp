#include "iter.hpp"



int main() {
    int array[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(array) / sizeof(array[0]);
    iter(array, length, printElement<int>);

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;

    char array2[] ={'a', 'b', 'c', 'd', 'e'};
    size_t length2 = sizeof(array2) / sizeof(array2[0]);
    iter(array2, length2, printElement<char>);
    
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;


    const int array3[] = {10, 11, 12, 13, 14};
    size_t length3 = sizeof(array3) / sizeof(array3[0]);
    iter(array3, length3, printElement<const int>);

    return 0;
}