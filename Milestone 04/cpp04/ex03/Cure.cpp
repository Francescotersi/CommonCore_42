#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure materia has beed created\n";
}

Cure::Cure(const Cure & other) : AMateria("cure")
{
	std::cout << "Cure materia has beed constructed from a copy\n";
	this->type = other.type;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure materia has beed destroyed\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}