#pragma once


#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <array>
#include <vector>

class IntegerNotFound: public std::exception {
    public:
        const char* what() const noexcept override {
            return "Integer not found";
        }
};


template <typename T>
int easyfind(T& container, int integer) {
    auto it = std::find(container.begin(), container.end(), integer);
    if (it == container.end())
    {
        throw IntegerNotFound();
    }
    return *it;
} 
