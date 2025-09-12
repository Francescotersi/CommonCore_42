#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constuctor of Cat called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assign operator of Cat called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW MEOW MEOW" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}

