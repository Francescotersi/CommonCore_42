#include "ScavTrap.hpp"

int main()
{
	const std::string separator(90, '=');
	std::cout << separator << std::endl;
	
	ScavTrap guy("Michele");

	guy.attack("Agata");
	guy.guardGate();
	guy.takeDamage(2);
	guy.beRepaired(5);

	std::cout << separator << std::endl;
	
	ScavTrap guy2("Nicola");

	guy.attack("Mario");
	guy.guardGate();
	guy.takeDamage(2);
	guy.beRepaired(5);
	
	return 0;
}