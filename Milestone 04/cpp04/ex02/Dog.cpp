#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default constuctor of Dog called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal()
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assign operator of Dog called" << std::endl;
	if (this != &other)
	{
		
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF WOOF" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

