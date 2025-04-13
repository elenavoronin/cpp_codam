#pragma once


#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

template <typename T, class C = std::deque<T>> 
class MutantStack : public std::stack<T, C> {

    public:
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack& operator=(const MutantStack &copy);
        ~MutantStack();

        using iterator = typename std::stack<T>::container_type::iterator;
        using const_iterator = typename std::stack<T>::container_type::const_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        void printStack() const;

};


#include "MutantStack.tpp"