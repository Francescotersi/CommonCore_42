#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Default construstor of ScavTrap called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	this->name = other.getName();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Operator overload of ScavTrap called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << name << "can`t do anything, he is too tired" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << name << " attacks " << target << " for " << attackDamage << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in guard keeper mode" << std::endl;
}
