#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	const std::string separator(90, '=');
	std::cout << separator << std::endl;
	
	FragTrap guy("Michele");

	guy.attack("Agata");
	guy.highFivesGuys();
	guy.takeDamage(2);
	guy.beRepaired(5);

	std::cout << separator << std::endl;
	
	FragTrap guy2("Nicola");

	guy.attack("Mario");
	guy.highFivesGuys();
	guy.takeDamage(2);
	guy.beRepaired(5);
	
	return 0;
}