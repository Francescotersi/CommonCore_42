#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : name(name)
{
	std::cout << "Character has beed created\n";
	for (int i = 0; i < 4; i++)
		this->spells[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
	std::cout << "Character has beed constructed from a copy\n";
	for (int i = 0; i < 4; i++)
		if (other.spells[i])
			this->spells[i] = other.spells[i]->clone();
		else
			this->spells[i] = NULL;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->spells[i])
				delete this->spells[i];
			this->spells[i] = NULL;
		}
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (other.spells[i])
				this->spells[i] = other.spells[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character has beed destroyed\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->spells[i])
			delete this->spells[i];
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->spells[i])
		{
			std::cout << "Materia equipped" << std::endl;
			this->spells[i] = m;
			return;
		}
	}
	std::cout << "Cannot equip materia: inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << "cant unequip materia, invalid inventory slot" << std::endl;
	else if (!(this->spells)[idx])
		std::cout << this->name << " has nothing equipped at slot " << idx << std::endl;
	else
	{
		AMateria *ptr = (this->spells)[idx];
		std::cout << this->name << " unequipped " << ptr->getType() << " at slot "<< idx << "\n";
		(this->spells)[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !(this->spells)[idx])
		std::cout << "cant use materia, invalid spell" << std::endl;
	else
	{
		this->spells[idx]->use(target);
	}
}

AMateria	*Character::getSpell(int idx)
{
	return (this->spells)[idx];
}
