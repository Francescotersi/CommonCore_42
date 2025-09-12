#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Default constuctor of Cat called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assign operator of Cat called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW MEOW MEOW" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}
