#include "MutantStack.hpp"

template <typename T, class C> 
MutantStack<T, C>::MutantStack() {}

template <typename T, class C> 
MutantStack<T, C>::MutantStack(const MutantStack &copy) {
    *this = copy;
}

template <typename T, class C> 
MutantStack<T,C>& MutantStack<T, C>::operator=(const MutantStack &copy) {
    if (this != &copy) {
        std::stack<T, C>::operator=(copy);
    }
    return *this;
}

template <typename T, class C> 
MutantStack<T, C>::~MutantStack() {}

template <typename T, class C> 
typename MutantStack<T, C>::iterator MutantStack<T,C>::begin() {
    return this->c.begin();
}

template <typename T, class C> 
typename MutantStack<T, C>::iterator MutantStack<T,C>::end() {
    return this->c.end();
}

template <typename T, class C> 
typename MutantStack<T, C>::const_iterator MutantStack<T,C>::begin() const {
    return this->c.begin();
}

template <typename T, class C> 
typename MutantStack<T, C>::const_iterator MutantStack<T,C>::end() const{
    return this->c.end();
}


template <typename T, class C> 
void MutantStack<T,C>::printStack() const {
    for (unsigned long i = 0; i < this->c.size(); i++) {
        std::cout << this->c[i] << " ";
    }
    std::cout << std::endl;
}
