#include "Span.hpp"

int main()
{
	try
	{
		Span span(4);

		span.addNumber(1);
		span.addNumber(30);
		span.addNumber(100);
		span.addNumber(11);

		span.shortestSpan();
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span span(1);

		span.addNumber(1);
		span.addNumber(30);

		span.shortestSpan();
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span span(3);

		span.generateNumbers();

		span.shortestSpan();
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}