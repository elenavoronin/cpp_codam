#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Span {
    private:
        unsigned int    N;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span& operator=(const Span &copy);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

};