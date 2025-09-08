#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


// per un point fuori dal trinangolo point(30, 15)
int main( void )
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point point(0, 0);

	if (bsp(a, b, c, point) == true)
		std::cout << "The point is inside the triangle! (THUNDER CROSS SPLIT ATTACK!)" << std::endl;
	else
		std::cout << "The point is NOT inside the triangle!!! (MUDA MUDA MUDA MUDAAAAAA!!!)" << std::endl;
	return (0);
}
