#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const & src)
{
    *this = src;
}

template <typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator=(MutantStack<T, Container> const & src)
{
    if (this != &src)
        this->c = src.c;
    return *this;
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::getBegin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::getEnd()
{
    return this->c.end();
}
