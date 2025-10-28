#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>

// helper: binary insert into a sorted vector
template <typename T>
void binaryInsert(std::vector<T> &seq, const T &value)
{
	typename std::vector<T>::iterator it = std::lower_bound(seq.begin(), seq.end(), value);
	seq.insert(it, value);
}

// Ford-Johnson (merge-insertion) sort for containers of int-like values
// Accepts a pointer to a container (std::vector<int> or std::deque<int>)
template <typename Container>
void fordJohnsonSort(Container *container)
{
	typedef typename Container::value_type T;
	if (container->size() < 2)
		return;

	std::vector<T> grandi;
	std::vector<T> piccoli;

	// form ordered pairs (small, big)
	for (size_t i = 0; i + 1 < container->size(); i += 2)
	{
		T a = (*container)[i];
		T b = (*container)[i + 1];
		if (a < b)
		{
			piccoli.push_back(a);
			grandi.push_back(b);
		}
		else
		{
			piccoli.push_back(b);
			grandi.push_back(a);
		}
	}

		std::cout << "PICCOLI: ";
		for (size_t i = 0; i < piccoli.size(); ++i) {
			if (i) std::cout << '\n';
			std::cout << piccoli[i];
		}
		std::cout << "\n\n";

		std::cout << "GRANDI: ";
		for (size_t i = 0; i < grandi.size(); ++i) {
			if (i) std::cout << '\n';
			std::cout << grandi[i];
		}
		std::cout << "\n\n";

	// if odd, keep the last element as 'small' to insert later
	if (container->size() % 2 == 1)
		piccoli.push_back((*container)[container->size() - 1]);

	// sort the sequence of grandes
	std::sort(grandi.begin(), grandi.end());

	// insert each piccolo into the sorted grandi using binary insertion
	for (typename std::vector<T>::size_type i = 0; i < piccoli.size(); ++i)
		binaryInsert(grandi, piccoli[i]);

	// move result back into the container
	container->clear();
	for (typename std::vector<T>::size_type i = 0; i < grandi.size(); ++i)
		container->push_back(grandi[i]);
}

// convenience overload: accept container by reference
template <typename Container>
void fordJohnsonSort(Container &container)
{
	fordJohnsonSort(&container);
}

#endif