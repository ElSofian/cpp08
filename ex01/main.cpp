#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    // Error with only one element

    Span sp2 = Span(1);
    sp2.addNumber(1);
    
    try {
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    // Error with too many elements

    Span sp3 = Span(5);
    sp3.addNumber(1);
    sp3.addNumber(2);
    sp3.addNumber(3);
    sp3.addNumber(4);
    sp3.addNumber(5);

    try {
        sp3.addNumber(6);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        sp3.addNumber(6, 10);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}