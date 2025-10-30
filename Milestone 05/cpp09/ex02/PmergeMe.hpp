#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <valarray>
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

template <typename T>
T fordJohnsonSort(T container)
{
	int temp = 0;
	switch (container.size()) // casi specifici a 1 e 2 numeri
	{
		case 1:
			return container;
		case 2:
			if (container.front() < container.back())
				return container;
			temp = container.back();
			container.pop_back();
			container.insert(container.begin(), temp);
			return container;
	}


	T big;
	T small;

	for (typename T::iterator it = container.begin(); it < container.end(); it += 2)
	{
		int num = *it;
		int num2 = 0;

		if (it + 1 != container.end())
			num2 = *(it + 1);
		else
		{
			small.push_back(num);
			break;
		}

		if (num > num2)
		{
			big.push_back(num);
			small.push_back(num2);
		}
		else
		{
			big.push_back(num2);
			small.push_back(num);
		}
	}

	if (big.size() > 1)
		big = fordJohnsonSort(big); // ricorsione
	
	small = jacobstalSequence(small); // jacobstal = ordinamento dei small in modo strategico
	
	for (typename T::iterator it = small.begin(); it < small.end(); it++) // si mette small dentro big in modo ordinato
	{
		typename T::iterator position = std::lower_bound(big.begin(), big.end(), *it);

		big.insert(position, *it);
	}

	return big;
}



#endif