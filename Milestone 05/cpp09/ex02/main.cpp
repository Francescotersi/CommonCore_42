#include "PmergeMe.hpp"

// must use merge-insert sort must use Ford-Johnson algorithm

// must use two different containers

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw ErrorMessage("Error : not enough numbers");
		
		std::vector<int> vect;
		std::deque<int> deque;

		fillContainer(&vect, argv);
		fillContainer(&deque, argv);

		vect = fordJohnsonSort(vect);
		deque = fordJohnsonSort(deque);

		std::cout << "Vector:" << std::endl;
		for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it)
			std::cout << *it << '\n';

		std::cout << "Deque:" << std::endl;
		for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); ++it)
			std::cout << *it << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
