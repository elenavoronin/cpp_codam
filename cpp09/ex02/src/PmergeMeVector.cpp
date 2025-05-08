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
        losers.push_back(last);
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
        
    mergeSort(winners, 0, winners.size() - 1);
    // ::insertBalanced(winners, losers, 0, losers.size() - 1);
    setVector(winners);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	setTimeVector(duration);
}


void PmergeMe::merge(std::vector<int>& vector, int left, int right, int mid) {
    int l = mid - left + 1;
    int r = right - mid;
    
    std::vector<int> L(l), R(r);
    for (int i = 0; i < l; i++) {
        L[i] = vector[left + i];
    }
    for (int j = 0; j < r; j++) {
        R[j] = vector[mid + 1 + j];
    }
    std::cout << "l, r: " << l << ", " << r << std::endl;
    std::cout << "Left: ";
    printVector(L);   
    std::cout << "Right: ";
    printVector(R);
    int i = 0;
    int j = 0;
    int k = left;
    while (i < l && j < r) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        }
        else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < l) {
        vector[k] = L[i];
        i++;
        k++;
    }
    while (j < r) {
        vector[k] = R[j];
        j++;
        k++;
    }
    std::cout << "vector: ";
    printVector(vector);
}

void PmergeMe::mergeSort(std::vector<int>& vector, int left, int right) {
    if (left >= right)
        return ;
    int mid = left + (right - left) / 2;
    mergeSort(vector, left, mid);
    mergeSort(vector, mid + 1, right);
    merge(vector, left, right, mid);

}


void PmergeMe::printVector(const std::vector<int>& vector) const {
    for (auto it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


