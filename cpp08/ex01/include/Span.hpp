#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <array>
#include <vector>
#include <numeric>

class Span {
    private:
        unsigned int        N;
        std::vector<int>    container;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span& operator=(const Span &copy);
        ~Span();
        
        class ContainerFull: private std::exception {
            const char* what() const noexcept override {
                return "The Container is aready full";
            }
        };

        class NoSpanPossible: private std::exception {
            const char* what() const noexcept override {
                return "The Container has too few elements to compute a span";
            }
        };
        
        
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        
        void addManyNumbers();

        void printSpan() const;

        int operator[](int index);

        size_t getSize() const;
};
    

    