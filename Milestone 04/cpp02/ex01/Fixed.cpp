#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called " << std::endl;
	this->fixed_value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Int constructor called" << std::endl;
	this->fixed_value = number << this->bits;
}

Fixed::Fixed(const float number)
{
	// conversione in fixed da float
	std::cout << "Float constructor called" << std::endl;
	this->fixed_value =  number * (1 << this->bits) + (number >= 0 ? 0.5 : -0.5);
}

int	Fixed::toInt() const
{

	return this->fixed_value >> this->bits;
}

float	Fixed::toFloat() const
{
	float result = this->fixed_value >> this->bits;

	result += (this->fixed_value % (1 << this->bits)) * (1.0 / (1 << bits));
	return result;
}