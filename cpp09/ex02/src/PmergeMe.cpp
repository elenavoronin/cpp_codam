#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
    if (this != &copy) {
        this->vector = copy.vector;
        this->deque = copy.deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::checkInput(const std::string& input) {
    for (unsigned long i = 0; i < input.size(); i++) {
        if (!isdigit(input[i]) && input[i] < 0) {
            throw WrongInput();
        }
    }
    populateContainer(input);
}

void PmergeMe::populateContainer(const std::string& input) {
    int nr = std::stoi(input);
    this->vector.push_back(nr);
    this->deque.push_back(nr);
    if (!checkDups(vector))
        throw WrongInput();
}

bool PmergeMe::checkDups(const std::vector<int>& vector) {
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


const std::vector<int> PmergeMe::getVector() const {
    return this->vector;
}

const std::deque<int> PmergeMe::getDeque() const {
    return this->deque;
}

void PmergeMe::setVector(std::vector<int>& vector) {
    this->vector = vector;
}

void PmergeMe::setDeque(std::deque<int>& deque) {
    this->deque = deque;
}

void PmergeMe::setTimeVector(long long ms) {
	this->timeVector = ms;
}

void PmergeMe::setTimeDeque(long long ms) {
	this ->timeDeque = ms;
}

long long PmergeMe::getTimeVector() const {
	return this->timeVector;
}

long long PmergeMe::getTimeDeque() const {
	return this->timeDeque;
}
