#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <stdexcept>
#include <algorithm>

class NotFoundException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Value not found";
        }
};

template <typename T>
void easyfind(T &container, int value)
{
	typename T::iterator res;

    res = find(container.begin(), container.end(), value);
    try
    {
        if (res == container.end())
        {
            throw NotFoundException();
            return ;
        }
        else
            std::cout << "Value found at index : " << std::distance(container.begin(), res) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    };
}
