#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>


class ErrorMessage : public std::exception
{
	private:
		const char *message;
	public:
		ErrorMessage(const char* str) : message(str){}
		virtual const char* what() const throw()
		{
			return message;
		}
};

template <typename T>
void fillContainer(T *container, char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		int number = std::atoi(argv[i]);
		if (number < 0)
			throw ErrorMessage("Error : found a negative number");
		container->push_back(number);
	}

}


template <typename T>
void fordJohnsonSort(T *container)
{
	int temp = 0;
	switch (container->size())
	{
		case 1:
			return ;
		case 2:
			if (container->front() < container->back())
				return ;
			temp = container->back();
			container->pop_back();
			container->insert(container->begin(), temp);
			return ;
	}
	// i love how it jiggles
}

#endif