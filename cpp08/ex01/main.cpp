#include "Span.hpp"

int main() {

    Span spanO;
    Span spanA(5);
    Span spanB(spanA);
    Span spanC(10001);

    spanA.addNumber(10);
    spanA.addNumber(27);
    spanA.addNumber(3);
    spanA.addNumber(-4);
    spanA.addNumber(-1005);

    spanA.printSpan();
    std::cout << "shortest span: " << spanA.shortestSpan() << std::endl;
    std::cout << "longest span: " << spanA.longestSpan() << std::endl;

    std::cout << "________________________" << std::endl;
    spanB.addManyNumbers();
    spanB.printSpan();
    std::cout << "shortest span: " << spanB.shortestSpan() << std::endl;
    std::cout << "longest span: " << spanB.longestSpan() << std::endl;

    std::cout << "________________________" << std::endl;

    spanC.addManyNumbers();
    std::cout << "spanC size: " << spanC.getSize() << std::endl;
    std::cout << "spanC[0]: " << spanC[0] << std::endl;
    std::cout << "spanC[100]: " << spanC[100] << std::endl;
    std::cout << "spanC[9999]: " << spanC[9999] << std::endl;
    std::cout << "spanC[10000]: " << spanC[10000] << std::endl;

    std::cout << "shortest span: " << spanC.shortestSpan() << std::endl;
    std::cout << "longest span: " << spanC.longestSpan() << std::endl;

    try {
        std::cout << "spanC[10001]: " << spanC[10001] << std::endl;
    }
    catch (std::exception e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }


    return 0;
}

