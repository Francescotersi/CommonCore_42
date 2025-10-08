#include <iostream>
#include <algorithm>

// A container is a holder object that stores a collection
// of other objects (its elements). They are implemented as class
// templates, which allows great flexibility in the data types supported.

template <typename T>
void easyfind(T _container, int _find)
{
	typename T::iterator i = std::find(_container.begin(), _container.end(), _find);
	if (*i == _find)
	{
		std::cout << "Found occurrance" << std::endl;
		return ;
	}
	throw notFound();
}
