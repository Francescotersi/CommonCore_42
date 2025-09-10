#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Default constructor of DiamondTrap called" << std::endl;
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
	this->name = other.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = FragTrap::hitPoints;
		this->energyPoints = ScavTrap::energyPoints;
		this->attackDamage = FragTrap::attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap Called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond name = " << name << ", ClapTrap name = " << ClapTrap::name << std::endl;
}