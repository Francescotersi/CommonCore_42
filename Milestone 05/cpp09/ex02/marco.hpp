#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <deque>
# include <sys/time.h>
# include <vector>
# include <iomanip>
# include <cmath>

template<typename T>
T getSeq(T vet)
{
	T	seq;
	T	vet2;
	T	temp;
	int	n;

	if (static_cast<int>(vet.size()) < 3)
		return vet;
	for (int i = 2; i <= static_cast<int>(vet.size()); i++)
	{
		n = (pow(2, i) - (pow(-1, i))) / 3;
		if (n > 0 && n < static_cast<int>(vet.size()))
			seq.push_back(n);
	}
	for (int i = 0; i < static_cast<int>(vet.size()); i++)
	{
		if (std::find(seq.begin(), seq.end(), i + 1) == vet.end())
			temp.push_back(vet[i]);
		else
			vet2.push_back(vet[i]);
	}
	for (typename T::iterator it = temp.begin(); it != temp.end(); it++)
	{
		vet2.push_back(*it);
	}
	return vet2;
}

template<typename T>
T createVector(char** mtrx)
{
	T vet;

	for (int i = 0; mtrx[i]; i++)
		vet.push_back(atoi(mtrx[i]));
	return vet;
}

template<typename T>
T sortVector(T vet)
{
	T	small;
	T	large;

	if (vet.size() == 1)
		return vet;
	else if (vet.size() == 2)
	{
		if (vet[0] < vet[1])
			return vet;
		else
		{
			T n;

			n.push_back(vet.back());
			n.push_back(vet.front());
			return n;
		}
	}
	for (typename T::iterator it = vet.begin(); it != vet.end(); it += 2)
	{
		int	n1 = *it;
		int	n2;

		if (it + 1 != vet.end())
			n2 = *(it + 1);
		else
		{
			small.push_back(n1);
			break;
		}
		if (n1 < n2)
		{
			small.push_back(n1);
			large.push_back(n2);
		}
		else
		{
			small.push_back(n2);
			large.push_back(n1);
		}
	}
    large = sortVector(large);
	small = getSeq(small);
    for (size_t i = 0; i < small.size(); ++i)
    {
		size_t	left = 0;
		size_t	right = large.size();
        int		value = small[i];

        if (large.empty())
        {
            large.push_back(value);
            continue;
        }
        while (left < right)
		{
			size_t	mid = left + (right - left) / 2;

			if (large[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		large.insert(large.begin() + left, value);
    }
    return large;
}

#endif