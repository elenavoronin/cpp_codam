#include "Span.hpp"

Span::Span(): N(0), container() {
}

Span::Span(unsigned int n): N(n)  {
    container.reserve(N);
}

Span::Span(const Span &copy) {
    *this = copy;
}

Span& Span::operator=(const Span &copy) {
    if (this != &copy) {
        N = copy.N;
        container.resize(N);
        for (unsigned long i = 0; i < container.size(); i++) {
            container[i] = copy.container[i];
        }
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (container.size() == N) {
        throw ContainerFull();
    }
    else {
        container.push_back(num);
    }
}

int Span::shortestSpan() {
    if (container.size() < 2)
        throw NoSpanPossible();

    std::sort(container.begin(), container.end());
    std::vector<int> Res(getSize());
    std::adjacent_difference(container.begin(), container.end(), Res.begin());
    std::generate(Res.begin(), Res.end(), [it = Res.begin()]() mutable {return ( abs(*(it++)));});
    return (*std::min_element(Res.begin() + 1, Res.end()));

}

int Span::longestSpan() {
    if (container.size() < 2)
    throw NoSpanPossible();
    
    auto [minIt, maxIt] = std::minmax_element(container.begin(), container.end());
    return (*maxIt - *minIt);

}


void Span::addManyNumbers() {
    container.resize(N);
    std::generate(container.begin(), container.end(), [n = 1] () mutable {return n++; });
}

void Span::printSpan() const {
    for (unsigned long i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

int Span::operator[](int index) {
    if (static_cast<unsigned long>(index) >= container.size())
        throw std::out_of_range("Index out of bounds");
    return container[index];
}

size_t Span::getSize() const {
    return this->container.size();
}