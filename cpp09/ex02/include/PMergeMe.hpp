#pragma once


#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <stdexcept>
#include <algorithm>

class PMergeMe {
    private:
        std::vector<int>    vector;
        std::deque<int>     deque;
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
};


template <typename T>
void binaryInsert(T container, int value) {
    auto it = std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
}

template <typename T>
void insertBalanced(T winners, T losers, int left, int right) {
    if (left > right)
        return ;
    int mid = left + (right - left) / 2;
    binaryInsert(winners, losers[mid]);

    insertBalanced(winners, losers, left, mid - 1); //left subtree
    insertBalanced(winners, losers, mid + 1, right); //right subtree
}