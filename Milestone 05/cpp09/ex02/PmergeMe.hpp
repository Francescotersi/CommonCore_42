#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <valarray>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <ctime>
#include <list>
#include <sys/time.h>
#include <climits>

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

void fillList(std::list<int> *list, char **argv);
std::list<int> fordJohnsonSortList(std::list<int> container);
std::vector<int> fordJohnsonSortVect(std::vector<int> container, std::vector<std::pair<int, int> > pairback);
std::deque<int> fordJohnsonSortDeque(std::deque<int> container, std::deque<std::pair<int, int> > pairback);

template <typename T>
void fillContainer(T *container, char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		long temp = std::atol(argv[i]);
		if (temp > INT_MAX)
			throw ErrorMessage("Error : a number is out of range");
		int number = std::atoi(argv[i]);
		if (number < 0)
			throw ErrorMessage("Error : found a negative number");
		container->push_back(number);
		for (int j = 0; argv[i][j]; j++)
			if (!std::isdigit(argv[i][j]))
				throw ErrorMessage("Error : something is not a number");
	}

}

template <typename T>
T jacobstalSequence(T small)
{
	T	jacobstal;
	size_t seqNum = 0;
	for (size_t i = 2; i <= small.size(); i++) // calcola la sequenza necessaria
	{
		seqNum = (pow(2, i) - (pow(-1, i))) / 3;
		if (seqNum < small.size())
			jacobstal.push_back(seqNum);
	}

	T temp;
	T finalContainer;
	for (size_t i = 0; i < small.size(); i++) // mette in temp i numeri non nella posizione della sequenza senno li mette in finalcontainer
	{
		if (std::find(jacobstal.begin(), jacobstal.end(), i + 1) == jacobstal.end())
			temp.push_back(small[i]);
		else
			finalContainer.push_back(small[i]);
	}

	for (typename T::iterator it = temp.begin(); it != temp.end(); it++)
		finalContainer.push_back(*it);
	return finalContainer;
}


#endif