#include <stack>
#include <deque>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public :
        MutantStack();
        ~MutantStack();
        MutantStack<T, Container>(MutantStack<T, Container> const & src);
        MutantStack<T, Container> &operator=(MutantStack<T, Container> const & src);

        typedef typename Container::iterator iterator;

        iterator getBegin();
        iterator getEnd();
};