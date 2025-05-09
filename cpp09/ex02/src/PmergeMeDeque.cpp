#include "PmergeMe.hpp"

void PmergeMe::dequeSort() {
	auto start = std::chrono::high_resolution_clock::now();
    std::deque<int> winners, losers;
    std::deque<int> deque = getDeque();
    int last = -1;
    if (deque.size() % 2 != 0) {
        last = deque[deque.size() -1];
        deque.pop_back();
    }
    for (auto it = deque.begin(); it != deque.end(); it += 2) {
        int current = *it;
        int next = *(it + 1);
        if (current > next) {
            winners.push_back(current);
            losers.push_back(next);
        }
        else {
            winners.push_back(next);
            losers.push_back(current);
        }
    }
    if (last >= 0)
        losers.push_back(last);
    ::mergeSort(winners, 0, winners.size() - 1);
    ::insertBalanced(winners, losers, 0, losers.size() - 1);
    setDeque(winners);

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	setTimeDeque(duration);
}


void PmergeMe::printDeque(const std::deque<int>& deque) const {
    for (auto it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
