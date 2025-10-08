#include "Span.hpp"

Span::Span(unsigned int N)
{
	if (N <= 1)
	{
		throw notEnoughNumbers();
	}
	numbers.reserve(N);
}

Span::Span(const Span& other)
{
	this->numbers = other.numbers;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->numbers = other.numbers;
	}
	return *this;
}

Span::~Span()
{

}

void Span::addNumber(int i)
{
	this->numbers.push_back(i);
}

void Span::longestSpan()
{
	std::vector<int>::iterator max;
	max = std::max_element(numbers.begin(), numbers.end());

	std::vector<int>::iterator min;
	min = std::min_element(numbers.begin(), numbers.end());
	int i = *max - *min;
	std::cout << "Longest span : " << i << std::endl;
}

void Span::shortestSpan() // non funziona rifallo
{
	std::sort(numbers.begin(), numbers.end());

	std::vector<int>::iterator end = numbers.end();
	std::vector<int>::iterator i = numbers.begin();
	std::vector<int>::iterator j;
	unsigned int diff = 0;
	unsigned int smallest = 0;
	while (i < end)
	{
		j = i + 1;
		diff = std::abs(*i - *j);
		if (diff < smallest)
			smallest = diff;
		i++;
	}
	std::cout << "Shortest span :" << smallest << std::endl;
}