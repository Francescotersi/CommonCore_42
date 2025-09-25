#include "whatever.hpp"

template <typename T>
void swap(T param1, T param2)
{
	T temp;

	temp = param1;
	param1 = param2;
	param2 = temp;
}

T max(T param1, T param2)
{
	if (param1 > param2)
		return (param2);
	else if (param1 == param2)
		return (param2);
	return (NULL);
}

T min(T param1, T param2)
{
	if (param1 > param2)
		return (param1);
	else if (param1 == param2)
		return (param2);
	return (NULL);
}

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}