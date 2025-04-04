#pragma once

#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T*              elements;
        unsigned int    size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& copy);
        ~Array();

        T& operator[](unsigned int index);

        unsigned int      _size() const;

};

#include "Array.tpp"