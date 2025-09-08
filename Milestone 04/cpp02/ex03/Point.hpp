#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(); //x e y init a 0
		Point(const Point& other); //copy consructor
		Point(const float xFloat, const float yFloat);
		Point& operator=(const Point& other);
		~Point();

		int getFixedX( void ) const ;
		int	getFixedY( void ) const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif