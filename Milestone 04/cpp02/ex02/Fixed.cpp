#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	this->fixed_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixed_value = other.getRawBits();
	return *this;
}

// override operatore << per stampare i valori all`interno della classe
std::ostream& operator<<(std::ostream& output, const Fixed& a)
{
	output << (a.toFloat());
	return (output);
}

Fixed::~Fixed()
{
	return ;
}

int Fixed::getRawBits() const
{
	return (this->fixed_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
	return ;
}

Fixed::Fixed(const int number)
{
	// conversione in fixed da int
	this->fixed_value = number << this->bits;
}

Fixed::Fixed(const float number)
{
	// conversione in fixed da float
	this->fixed_value =  number * (1 << this->bits) + (number >= 0 ? 0.5 : -0.5);
}

int	Fixed::toInt() const
{
	// conversione in int da fixed
	return this->fixed_value >> this->bits;
}

float	Fixed::toFloat() const
{
	// conversione in float da fixed
	float result = this->fixed_value >> this->bits;

	result += (this->fixed_value % (1 << this->bits)) * (1.0 / (1 << bits));
	return result;
}


// -------------comparison operators--------------
bool Fixed::operator>(const Fixed& other) const
{
	return fixed_value > other.fixed_value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return fixed_value < other.fixed_value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return fixed_value >= other.fixed_value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return fixed_value <= other.fixed_value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return fixed_value == other.fixed_value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return fixed_value != other.fixed_value;
}

// -------------arithmetic operators--------------

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed temp;
	temp.fixed_value = fixed_value + other.fixed_value;
	return temp;
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed temp;
	temp.fixed_value = fixed_value - other.fixed_value;
	return temp;
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed temp;
	temp.fixed_value = (this->fixed_value * other.fixed_value) / (1 << bits);
	return temp;
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed temp;
	temp.fixed_value = ((float)this->fixed_value / other.fixed_value) * (1 << bits);
	return temp;
}

// ---------increment/decrement operators---------

Fixed& Fixed::operator++()
{
	++fixed_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	fixed_value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	--fixed_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	fixed_value--;
	return temp;
}

// ---------max and min---------------------------

Fixed& Fixed::min(Fixed& other1, Fixed& other2)
{
	if (other1.fixed_value < other2.fixed_value)
		return other1;
	return other2;
}

const Fixed& Fixed::min(const Fixed& other1, const Fixed& other2)
{
	if (other1.fixed_value < other2.fixed_value)
		return other1;
	return other2;
}

Fixed& Fixed::max(Fixed& other1, Fixed& other2)
{
	if (other1.fixed_value > other2.fixed_value)
		return other1;
	return other2;
}

const Fixed& Fixed::max(const Fixed& other1, const Fixed& other2)
{
	if (other1.fixed_value > other2.fixed_value)
		return other1;
	return other2;
}
