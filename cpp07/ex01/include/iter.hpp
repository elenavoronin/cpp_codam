#pragma once
#include <cstddef>
#include <iostream>

template <typename T, typename S, typename F>
void iter(T* array, S length, F function)
{
    for (S i = 0; i < length; i++) {
        function(array[i]);
    }
}

template <typename P>
void printElement(P element) {
    std::cout << element << " ";
}

