#include "easyfind.hpp"


int main(void)
{
    
    std::array<int, 3> Array = {10, 15, 2555};
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    
    std::cout << easyfind(Array, 10) << std::endl;
    std::cout << easyfind(v, 10) << std::endl;
    std::cout << easyfind(v, 1) << std::endl;
    
    try
    {
        std::cout << easyfind(Array, 100) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << easyfind(v, 9) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    }

    return 0;
}