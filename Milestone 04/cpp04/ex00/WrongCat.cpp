#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default constuctor of WrongCat called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy assign operator of WrongCat called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WRONG CAT SOUNDS" << std::endl;
}

std::string WrongCat::getType() const
{
	return this->type;
}
