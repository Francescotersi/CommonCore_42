#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constuctor of WrongAnimal called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Copy assign operator of WrongAnimal called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WRONG ANIMAL SOMETHING" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}