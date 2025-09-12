#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constuctor of Brain called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor of Brain called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.getIdeas(i);
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Copy assign operator of Brain called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.getIdeas(i);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

std::string Brain::getIdeas(int i) const
{
	return this->ideas[i];
}
