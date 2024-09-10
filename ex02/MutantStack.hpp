#include <stack>
#include <deque>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public :
        MutantStack(): std::stack<T, Container>() {}
        ~MutantStack() {}
        MutantStack<T, Container>(MutantStack<T, Container> const & src) { *this = src; }
        MutantStack<T, Container> &operator=(MutantStack<T, Container> const & src)
        {
            if (this != &src)
                this->c = src.c;
            return *this;
        }

        typedef typename Container::iterator iterator;

        iterator getBegin() {return this->c.begin();};
        iterator getEnd() {return this->c.end();};
};