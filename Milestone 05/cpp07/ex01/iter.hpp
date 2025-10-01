#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename L, typename F>
void iter(T *addr, const L length, F funct)
{
    for (int i = 0; i < length; i++)
        funct(addr[i]);
}

// ----------------------------------------------

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x)
{
    ++x;
}

#endif