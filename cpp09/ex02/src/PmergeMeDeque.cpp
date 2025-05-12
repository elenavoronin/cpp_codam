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
    insertLoserDeque(winners, losers);
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

void PmergeMe::insertLoserDeque(std::deque<int>& winners, std::deque<int>& losers) {
	std::deque<int> jacobsthalDeque;
	int j0 = 0, j1 = 1;
	jacobsthalDeque.push_back(j0);
	if (losers.size() > 1)
		jacobsthalDeque.push_back(1);

	while (true) {
		int next = j1 + 2 * j0;
		if (next >= static_cast<int>(losers.size()))
			break;
		jacobsthalDeque.push_back(next);
		j0 = j1;
		j1 = next;
	}

	std::sort(jacobsthalDeque.begin(), jacobsthalDeque.end());
    jacobsthalDeque.erase(std::unique(jacobsthalDeque.begin(), jacobsthalDeque.end()), jacobsthalDeque.end());
	
	std::vector<bool> inserted(losers.size(), false);
	for (int index : jacobsthalDeque) {
		if (index >= 0 && index < static_cast<int>(losers.size())) {
			binaryInsert(winners, losers[index], 0, winners.size() - 1);
			inserted[index] = true;
		}
	}

	for (size_t i = 0; i < losers.size(); i++) {
		if (!inserted[i])
			binaryInsert(winners, losers[i], 0, winners.size() - 1);
	}
}
