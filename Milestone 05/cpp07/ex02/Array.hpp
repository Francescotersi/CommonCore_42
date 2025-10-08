#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
		T *array;
		size_t arrSize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		class indexTooBig : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index is too big";
				}
		};

		T& operator[](size_t index);
		size_t size() const;

};

#include "Array.tpp"

#endif