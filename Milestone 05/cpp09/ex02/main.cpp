#include "PmergeMe.hpp"

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

		std::cout << "Before: " << std::endl;
		for (int i = 1; argv[i]; i++)
			std::cout << argv[i] << ' ';
		std::cout << std::endl;
		std::cout << std::endl;

		struct timeval start;
		struct timeval end;
		double vectElapsed;
		double dequeElapsed;

		std::vector<std::pair<int, int> > pair_v;
		gettimeofday(&start, NULL);
		vect = fordJohnsonSortVect(vect, pair_v); //

		gettimeofday(&end, NULL);
		vectElapsed = static_cast<double>((end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec));
		
		std::deque<std::pair<int, int> > pair_d;
		gettimeofday(&start, NULL);
		deque = fordJohnsonSortDeque(deque, pair_d); //

		gettimeofday(&end, NULL);
		dequeElapsed = static_cast<double>((end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec));



		std::cout << "After: " << std::endl;
		for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it)
			std::cout << *it << ' ';
		std::cout << std::endl;
		std::cout << std::endl;


		std::cout << "Time to process a range of "
		<< vect.size()
		<< " elements with std::vector : "
		<< vectElapsed << "m/s"
		<< std::endl;

		std::cout << "Time to process a range of "
		<< deque.size()
		<< " elements with std::deque : "
		<< dequeElapsed << "m/s"
		<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
