#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constuctor of Animal called" << std::endl;
	this->type = "Some animal idk";
}

Animal::Animal(std::string type)
{
	this->type = type;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor of Animal called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy assign operator of Animal called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called" << std::endl;
}

// void Animal::makeSound() const
// {
// 	std::cout << "No sounds i am an animal" << std::endl;
// }

std::string Animal::getType() const
{
	return this->type;
}
