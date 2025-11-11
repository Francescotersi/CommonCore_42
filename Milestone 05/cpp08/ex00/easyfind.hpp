#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

class notFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "occurrance not found :(";
		}
};

#include "easyfind.tpp"

#endif