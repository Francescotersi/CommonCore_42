#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "Default construstor of FragTrap called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	this->name = other.getName();
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Operator overload of FragTrap called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap displays a positive high-fives request" << std::endl;
}
