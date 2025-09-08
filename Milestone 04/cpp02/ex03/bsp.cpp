#include "Point.hpp"
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float area;
	
	area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	if (area < 0)
		area *= -1;
	area *= 0.5;
	return (area);
}

// • a, b, c: The vertices of our beloved triangle.
// • point: The point to check.
// • Returns: True if the point is inside the triangle. False otherwise.
// Thus, if the point is a vertex or on an edge, it will return False.
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	totalArea;
	float	areaOne;
	float	areaTwo;
	float	areaThree;

	totalArea = area(a.getFixedX(), a.getFixedY(),
					b.getFixedX(), b.getFixedY(),
					c.getFixedX(), c.getFixedY());

	areaOne = area(a.getFixedX(), a.getFixedY(),
					b.getFixedX(), b.getFixedY(),
					point.getFixedX(), point.getFixedY());

	areaTwo = area(a.getFixedX(), a.getFixedY(), 
					point.getFixedX(), point.getFixedY(),
					c.getFixedX(), c.getFixedY());

	areaThree = area(point.getFixedX(), point.getFixedY(), 
					b.getFixedX(), b.getFixedY(),
					c.getFixedX(), c.getFixedY());

	if (areaOne == 0.0 || areaTwo == 0.0 || areaThree == 0.0)
		return (false);
	else if (totalArea < areaOne + areaTwo + areaThree)
		return (false);
	return (true);
}