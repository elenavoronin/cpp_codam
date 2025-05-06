#pragma once


#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <chrono> 

class PMergeMe {
    private:
        std::vector<int>	 			vector;
        std::deque<int>    				deque;
        long long						timeVector;
        long long						timeDeque;
		
    public:
        PMergeMe();
        PMergeMe(const PMergeMe& copy);
        PMergeMe& operator=(const PMergeMe& copy);
        ~PMergeMe();

        void checkInput(const std::string& input);

        class WrongInput: public std::exception {
            const char* what() const noexcept override {
                return "The input should only contain non duplicated positive integers";
            }
        };

        const std::vector<int>   getVector() const;
        const std::deque<int>    getDeque() const;
        void                     setVector(std::vector<int>& vector);
        void                     setDeque(std::deque<int>& deque);
        void                      populateContainer(const std::string& input);
        void                      calculus();
        void                      vectorSort();
        void                      dequeSort();
        bool                      checkDups(const std::vector<int>& vector);

        void                      printVector(const std::vector<int>& vector) const;
        void                      printDeque(const std::deque<int>& deque) const;

		void					setTimeVector(long long ms);
		void					setTimeDeque(long long ms);
		long long				getTimeVector() const;;
		long long 				getTimeDeque() const;

};


template <typename T>
void binaryInsert(T& container, int value) {
	if (std::find(container.begin(), container.end(), value) != container.end()) {
        return; // Value already exists, do not insert
    }
	auto it = std::lower_bound(container.begin(), container.end(), value);
    if (it != container.end())
		container.insert(it, value);
}

template <typename T>
void insertBalanced(T& winners, const T& losers, int left, int right) {
    if (left > right)
        return ;
    int mid = left + (right - left) / 2;
	if (mid >= 0 && mid < static_cast<int>(losers.size()))
   		binaryInsert(winners, losers[mid]);

    insertBalanced(winners, losers, left, mid - 1); //left subtree
    insertBalanced(winners, losers, mid + 1, right); //right subtree
}
