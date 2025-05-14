#include "PmergeMe.hpp"

void PmergeMe::vectorSort() {
	auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> vector = getVector();
    std::vector<int> winners, losers;
    unsigned long i = 0;
    int last = -1;
    if (vector.size() % 2 != 0) {
        last = vector[vector.size() -1];
        vector.pop_back();
    }
    while (i < vector.size() - 1) {
        int current = vector[i];
        int next = vector[i + 1];
        if (current > next) {
            winners.push_back(current);
            losers.push_back(next);
        }
        else {
            winners.push_back(next);
            losers.push_back(current);
        }
        i += 2;
    }
    if (last >= 0)
        losers.push_back(last);
        
    ::mergeSort(winners, 0, winners.size() - 1);
    insertLoserVector(winners, losers);
    setVector(winners);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	setTimeVector(duration);
}

void PmergeMe::insertLoserVector(std::vector<int> & winners, std::vector<int> & losers) {
	std::vector<int> jacobsthalVector;
	int j0 = 0, j1 = 1;
	jacobsthalVector.push_back(j0);
	if (losers.size() > 1)
		jacobsthalVector.push_back(1);
	
	while (true) {
		int next = j1 + 2 * j0;
		if (next >= static_cast<int>(losers.size()))
			break;
		jacobsthalVector.push_back(next);
		j0 = j1;
		j1 = next;
	}
	
	std::sort(jacobsthalVector.begin(), jacobsthalVector.end());
    jacobsthalVector.erase(std::unique(jacobsthalVector.begin(), jacobsthalVector.end()), jacobsthalVector.end());

	std::vector<bool> inserted(losers.size(), false);
	for (size_t i = 0; i < jacobsthalVector.size(); ++i) {
        int index = jacobsthalVector[i];
		if (index >= 0 && index < static_cast<int>(losers.size())) {
            if (index == 0 || index == 1) {
                binaryInsert(winners, losers[index], 0, winners.size());
                inserted[index] = true;
            }
            else {
                binaryInsert(winners, losers[index], 0, winners.size());
                inserted[index] = true;
                int limit = index;
                index = jacobsthalVector[i - 1] + 1;
                while (index < limit) {
                    binaryInsert(winners, losers[index], 0, winners.size());
                    inserted[index] = true;
                    index++;
                }
            }
		}
	}
	for (size_t i = 0; i < losers.size(); i++) {
		if (!inserted[i])
			binaryInsert(winners, losers[i], 0, winners.size());
	}
}

void PmergeMe::printVector(const std::vector<int>& vector) const {
    for (const int& num : vector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
