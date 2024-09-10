#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &src) : _n(src._n), _v(src._v) {}

Span::~Span() {}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	_n = src._n;
	_v = src._v;
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw VectorIsFull();
	_v.push_back(n);
}

void Span::addNumber(int start, int end)
{
	if (_v.size() >= _n)
		throw VectorIsFull();
	if (start == end)
	{
		_v.push_back(start);
		return ;
	}
	if (start > end)
		throw VectorWillOverflow();
	while (start <= end)
	{
		if (_v.size() >= _n)
			throw VectorWillOverflow();
		_v.push_back(start);
		start++;
	}
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NotEnoughElements();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NotEnoughElements();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}