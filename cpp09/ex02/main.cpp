#include "PMergeMe.hpp"


int main(int argc, char** argv) {
    if (argc == 1)
        return 1;
    
	long long duration = 0;
    PMergeMe merge;
    try {
		auto start = std::chrono::high_resolution_clock::now();
        int i = 1;
        while (i < argc) {
            merge.checkInput(argv[i]);
            i++;
        }
        if (merge.checkDups(merge.getVector())) {
            std::cout << "Before: ";
            merge.printVector(merge.getVector());
        }
		auto end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    catch (std::exception &e) {
		std::cout << "Error occured: " << e.what() << std::endl;
		return 2;
	}

    merge.vectorSort();
    merge.dequeSort();

    std::cout << "After: ";
    merge.printVector(merge.getVector());

	std::cout << "Time to process a range of 3000 elements with std::vector: " << merge.getTimeVector() + duration << " ms." << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::deque: " << merge.getTimeDeque() + duration << " ms." << std::endl;
    return 0;
}
