#include "PMergeMe.hpp"




PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe& copy) {
    *this = copy;
}

PMergeMe& PMergeMe::operator=(const PMergeMe& copy) {
    if (this != &copy) {
        this->vector = copy.vector;
        this->deque = copy.deque;
    }
    return *this;
}

PMergeMe::~PMergeMe() {}

void PMergeMe::checkInput(const std::string& input) {
    for (unsigned long i = 0; i < input.size(); i++) {
        if (!isdigit(input[i]) && input[i] < 0) {
            throw WrongInput();
        }
    }
    populateContainer(input);
}

void PMergeMe::populateContainer(const std::string& input) {
    int nr = std::stoi(input);
    this->vector.push_back(nr);
    this->deque.push_back(nr);
}

bool PMergeMe::checkDups(const std::vector<int>& vector) {
    unsigned long i = 0;
    unsigned long j = 1;
    while (i < vector.size()) {
        while (j < vector.size()) {
            if (vector[i] == vector[j])
                return false;
            else
                j++;
        }
        i++;
    }
    return true;
}

void PMergeMe::calculus() {

}

void PMergeMe::vectorSort() {
	auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> winners, losers;
    std::vector<int> vector = getVector();
    unsigned long i = 0;
    int last;
    if (vector.size() % 2 != 0) {
        last = vector[vector.size() -1];
        vector.pop_back();
        losers.push_back(last);
    }
    while (i < vector.size()) {
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
    if (last)
        losers.push_back(last);
    std::sort(winners.begin(), winners.end());
    ::insertBalanced(winners, losers, 0, losers.size() - 1);
    setVector(winners);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	setTimeVector(duration);
}

void PMergeMe::dequeSort() {
	auto start = std::chrono::high_resolution_clock::now();
    std::deque<int> winners, losers;
    std::deque<int> deque = getDeque();
    unsigned long i = 0;
    int last;
    if (deque.size() % 2 != 0) {
        last = deque[deque.size() -1];
        deque.pop_back();
    }
    while (i < deque.size()) {
        int current = deque[i];
        int next = deque[i + 1];
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
    if (last)
        losers.push_back(last);
    std::sort(winners.begin(), winners.end());
    ::insertBalanced(winners, losers, 0, losers.size() - 1);
    setDeque(winners);

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	setTimeDeque(duration);
}


const std::vector<int> PMergeMe::getVector() const {
    return this->vector;
}

const std::deque<int> PMergeMe::getDeque() const {
    return this->deque;
}

void PMergeMe::setVector(std::vector<int>& vector) {
    this->vector = vector;
}

void PMergeMe::setDeque(std::deque<int>& deque) {
    this->deque = deque;
}

void PMergeMe::printVector(const std::vector<int>& vector) const {
    for (auto it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PMergeMe::printDeque(const std::deque<int>& deque) const {
    for (auto it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void PMergeMe::setTimeVector(long long ms) {
	this->timeVector = ms;
}

void PMergeMe::setTimeDeque(long long ms) {
	this ->timeDeque = ms;
}

long long PMergeMe::getTimeVector() const {
	return this->timeVector;
}


long long PMergeMe::getTimeDeque() const {
	return this->timeDeque;
}
