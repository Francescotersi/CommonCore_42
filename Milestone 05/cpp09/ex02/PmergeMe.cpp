#include "PmergeMe.hpp"

// DIFFERENCE BETWEEN VECTORS AND DEQUES
// While vectors use a single array that needs to be occasionally
// reallocated for growth, the elements of a deque can be scattered in
// different chunks of storage, with the container keeping the necessary
// information internally to provide direct access to any of its elements
// in constant time and with a uniform sequential interface (through iterators). 


// JACOBSTAL
// sequenza di numeri come quella di fibonacci. Parte con i numeri 0, 1 
// poi ogni membro della sequenza viene formato sommando il numero predente
// con due volte il numero precedente ancora:
// 0, 1, 1, 3, 5, 11, 21, 43, 85, ......

std::vector<int> fordJohnsonSortVect(std::vector<int> container, std::vector<std::pair<int, int> > pairback)
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

	std::vector<std::pair<int, int> > checkPoint;

	if (!pairback.empty()) // serve per salvarsi l`iterazione
		checkPoint = pairback;

	pairback.clear();

	std::vector<int> big;
	std::vector<int> small;
	std::vector<int> odd;
	// coppie sono {maggiore, minore}

	if (container.size() % 2 != 0) // se input dispari mette da parte l`ultimo numero 
	{
		odd.push_back(container.back());
		container.pop_back();
	}

	for (std::vector<int>::size_type i = 0; i < container.size(); i += 2)
	{
    	int a = container[i];
    	int b = container[i + 1];
		
		if (a < b)
		{
			pairback.push_back(std::make_pair(b, a));
			big.push_back(b);
			small.push_back(a);
    	}
		else
		{
    	    pairback.push_back(std::make_pair(a, b));
    	    big.push_back(a);
			small.push_back(b);
		}
	}

	big = fordJohnsonSortVect(big, pairback); // ricorsione

	small = jacobstalSequence(small); // ordina small secondo la seq di jacobstal

	for (std::vector<int>::iterator itsmall = small.begin(); itsmall != small.end(); itsmall++)
	{
		int smallnum = *itsmall;
		int num = -1;
		for (std::vector<std::pair<int, int> >::iterator it = pairback.begin(); it != pairback.end(); it++)
		{
			if (it->second == smallnum)
			{
				num = it->first; // prendi il numero accoppiato a smallnum
				break ;
			}
		}
		if (num)
		{
			std::vector<int>::iterator itEnd = std::lower_bound(big.begin(), big.end(), num); // trovi iteratore end
			std::vector<int>::iterator pos = std::lower_bound(big.begin(), itEnd, smallnum); // mette numero nella pos con meno comparazioni

			big.insert(pos, smallnum);
		}
	}

	if (odd.size() > 0)
	{
		std::vector<int>::iterator pos = std::lower_bound(big.begin(), big.end(), odd.front());
		big.insert(pos, odd.front());
	}
	return big;
}

std::deque<int> fordJohnsonSortDeque(std::deque<int> container, std::deque<std::pair<int, int> > pairback)
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

	std::deque<std::pair<int, int> > checkPoint;

	if (!pairback.empty()) // serve per salvarsi l`iterazione
		checkPoint = pairback;

	pairback.clear();

	std::deque<int> big;
	std::deque<int> small;
	std::deque<int> odd;
	// coppie sono {maggiore, minore}

	if (container.size() % 2 != 0) // se input dispari mette da parte l`ultimo numero 
	{
		odd.push_back(container.back());
		container.pop_back();
	}

	for (std::deque<int>::size_type i = 0; i < container.size(); i += 2)
	{
    	int a = container[i];
    	int b = container[i + 1];
		
		if (a < b)
		{
			pairback.push_back(std::make_pair(b, a));
			big.push_back(b);
			small.push_back(a);
    	}
		else
		{
    	    pairback.push_back(std::make_pair(a, b));
    	    big.push_back(a);
			small.push_back(b);
		}
	}

	big = fordJohnsonSortDeque(big, pairback); // ricorsione

	small = jacobstalSequence(small); // ordina small secondo la seq di jacobstal

	for (std::deque<int>::iterator itsmall = small.begin(); itsmall != small.end(); itsmall++)
	{
		int smallnum = *itsmall;
		int num = -1;
		for (std::deque<std::pair<int, int> >::iterator it = pairback.begin(); it != pairback.end(); it++)
		{
			if (it->second == smallnum)
			{
				num = it->first; // prendi il numero accoppiato a smallnum
				break ;
			}
		}
		if (num)
		{
			std::deque<int>::iterator itEnd = std::lower_bound(big.begin(), big.end(), num); // trovi iteratore end
			std::deque<int>::iterator pos = std::lower_bound(big.begin(), itEnd, smallnum); // mette numero nella pos con meno comparazioni

			big.insert(pos, smallnum);
		}
	}

	if (odd.size() > 0)
	{
		std::deque<int>::iterator pos = std::lower_bound(big.begin(), big.end(), odd.front());
		big.insert(pos, odd.front());
	}
	return big;
}
