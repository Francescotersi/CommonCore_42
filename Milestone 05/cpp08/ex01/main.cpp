#include "Span.hpp"

int main()
{
	try
	{
		Span span(5);

		span.addNumber(1);
		span.addNumber(333);
		span.addNumber(443);
		span.addNumber(12);

		span.shortestSpan();
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}