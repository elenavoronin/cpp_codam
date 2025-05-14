#include "PmergeMe.hpp"


int main(int argc, char** argv) {
    long long duration = 0;
    if (argc == 1)
        return 1;

    PmergeMe merge;
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
    // std::cout << "Vector: ";
    merge.printVector(merge.getVector());
    // std::cout << "Deque: ";
    // merge.printDeque(merge.getDeque());

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << merge.getTimeVector() + duration  << " us." << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << merge.getTimeDeque() + duration << " us." << std::endl;
    return 0;
}
