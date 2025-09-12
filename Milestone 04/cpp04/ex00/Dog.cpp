#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constuctor of Dog called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assign operator of Dog called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF WOOF" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

