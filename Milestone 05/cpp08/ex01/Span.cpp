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

void Span::shortestSpan()
{
	std::sort(numbers.begin(), numbers.end());

	std::vector<int>::iterator num1 = numbers.begin();
	std::vector<int>::iterator num2 = num1 + 1;
	int temp = 0;
	int diff = -1;
	while (num2 < numbers.end())
	{
		temp =std::abs(*num1 - *num2);
		if (diff == -1 || temp < diff)
			diff = temp;
		num1++;
		num2++;
	}
	std::cout << "Shortest span :" << diff << std::endl;
}

void Span::generateNumbers()
{
	srand(time(0));

	for (int i = 0; i < 10000; i++)
		this->addNumber(rand());
}
