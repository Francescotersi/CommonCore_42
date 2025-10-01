#ifndef WHATERVER_HPP
# define WHATERVER_HPP

#include <iostream>

template <typename T>
void swap(T& param1, T& param2)
{
	T temp;

	temp = param1;
	param1 = param2;
	param2 = temp;
}

template <typename T>
T max(T param1, T param2)
{
	if (param1 > param2)
		return (param1);
	else if (param1 == param2)
		return (param2);
	return (0);
}

template <typename T>
T min(T param1, T param2)
{
	if (param1 > param2)
		return (param2);
	else if (param1 == param2)
		return (param2);
	return (0);
}

#endif