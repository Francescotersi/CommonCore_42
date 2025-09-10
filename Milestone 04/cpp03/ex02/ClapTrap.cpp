#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
	std::cout << "Default constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Default constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor of ClapTrap called" << std::endl;
	this->name = other.getName();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Operator overload of ClapTrap called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->attackDamage = other.getAttackDamage();
		this->energyPoints = other.getEnergyPoints();
		this->hitPoints = other.getHitPoints();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return this->name;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

int ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << name << "can`t do anything, he is too tired" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap with the name of " << name << " attacks " << target << " for " << attackDamage << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << name << " can`t do anything, he is too tired" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << name << " repairs itself for " << amount << " hit points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << name << " is already dead bro...." << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << name << "is hit by another guy" << " for " << amount << std::endl;
}
