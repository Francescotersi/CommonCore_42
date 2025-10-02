#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	array = new T [0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	array = new T [n]
}

template <typename T>
Array<T>::Array(const Array& other)
{
	
}
