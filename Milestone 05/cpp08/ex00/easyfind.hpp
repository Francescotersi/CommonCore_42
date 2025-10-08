#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

class notFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Non ho trovato nulla :(";
		}
};

#include "easyfind.tpp"

#endif