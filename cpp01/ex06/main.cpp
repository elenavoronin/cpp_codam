#include "Harl.hpp"
#include <iostream>
#include <string>



int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2)
    {
        std::cout << "Give Harl something to do" << std::endl;
        return 0;
    }
    std::string level = argv[1];
    // harl.complain(level);
    // harl.complain(level);
    harl.complain(level);
    // harl.complain(level);
    // harl.complain(level);

    return 0;
}