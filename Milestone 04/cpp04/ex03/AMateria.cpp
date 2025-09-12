#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "Abstract materia has beed created\n";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "Abstract materia has beed constructed\n";
	this->type = type;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "Abstract materia has beed constructed from a copy\n";
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "Abstract materia has beed destroyed\n";
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}

