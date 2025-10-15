#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int> numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int i);

		void shortestSpan();
		void longestSpan();

		void generateNumbers();
		class notEnoughNumbers : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Not enough numbers";
				}
		};
};

#endif