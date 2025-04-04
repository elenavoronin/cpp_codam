#include "Array.hpp"

template <typename T>
Array<T>::Array(): elements(nullptr), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): elements(nullptr), size(n) {
    if (n > 0) {
        elements = new T[n];
    }
}

template <typename T>
Array<T>::Array(const Array& copy): elements(nullptr), size(0) {
    *this = copy;
}

template <typename T> 
Array<T>& Array<T>::operator=(const Array<T>& copy) {
    if (this != &copy)
    {
        delete[] elements;
        size = copy.size;
        elements = new T[size];
        for (unsigned int i = 0; i < size; i++) {
            elements[i] = copy.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] elements;
    elements = nullptr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }    
    return elements[index];
}

template <typename T>
unsigned int Array<T>::_size() const {
    return size;
}