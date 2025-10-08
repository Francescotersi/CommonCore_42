#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), arrSize(0)
{
	std::cout << "created an empty array" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), arrSize(n)
{
	std::cout << "created a full array" << std::endl;
	if (arrSize > 0)
		array = new T[arrSize];
}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), arrSize(other.arrSize)
{
	if (arrSize > 0)
	{
		array = new T[arrSize];
		for (size_t i = 0; i < arrSize; ++i)
			array[i] = other.array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* newArr = NULL;
		if (other.arrSize > 0)
		{
			newArr = new T[other.arrSize];
			for (size_t i = 0; i < other.arrSize; ++i)
				newArr[i] = other.array[i];
		}
		delete [] array;
		array = newArr;
		arrSize = other.arrSize;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] array;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= arrSize)
		throw indexTooBig();
	return array[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return arrSize;
}
