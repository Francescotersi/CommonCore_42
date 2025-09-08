#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(const float xFloat, const float yFloat) : x(xFloat) , y(yFloat) {}

Point& Point::operator=(const Point& other)
{
	return *this;
}

Point::~Point() {};

int Point::getFixedX() const
{
	return (this->x.getRawBits());
}

int	Point::getFixedY() const
{
	return (this->y.getRawBits());
}
