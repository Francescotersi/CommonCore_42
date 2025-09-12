#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice materia has beed created\n";
}

Ice::Ice(const Ice & other) : AMateria("ice")
{
	std::cout << "Ice materia has beed constructed from a copy\n";
	this->type = other.type;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice materia has beed destroyed\n";
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "`s wounds *" << std::endl;
}