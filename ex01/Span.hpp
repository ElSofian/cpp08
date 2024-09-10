#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _v;

    public:
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);

        void addNumber(int n);
        void addNumber(int start, int end);
        int shortestSpan();
        int longestSpan();
};

class VectorIsFull : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Vector is full";
        }
};

class VectorWillOverflow : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Vector will overflow with that range";
        }
};

class NotEnoughElements : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Not enough elements to calculate span";
        }
};