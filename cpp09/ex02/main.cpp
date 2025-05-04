#include "PMergeMe.hpp"


int main(int argc, char** argv) {
    if (argc == 1)
        return 1;
    
    PMergeMe merge;
    try {
        int i = 1;
        while (i < argc) {
            merge.checkInput(argv[i]);
            i++;
        }
        if (merge.checkDups(merge.getVector())) {
            std::cout << "Before: ";
            merge.printVector(merge.getVector());
        }
    }
    catch (std::exception &e) {
        std::cout << "Error occured: " << e.what() << std::endl;
        return 2;
    }

    merge.vectorSort();
    merge.dequeSort();

    std::cout << "After: ";
    merge.printVector(merge.getVector());
    return 0;
}