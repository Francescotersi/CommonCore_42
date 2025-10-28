#include "PmergeMe.hpp"

// DIFFERENCE BETWEEN VECTORS AND DEQUES
// While vectors use a single array that needs to be occasionally
// reallocated for growth, the elements of a deque can be scattered in
// different chunks of storage, with the container keeping the necessary
// information internally to provide direct access to any of its elements
// in constant time and with a uniform sequential interface (through iterators). 
