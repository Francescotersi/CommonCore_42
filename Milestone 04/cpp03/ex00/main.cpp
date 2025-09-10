#include "ClapTrap.hpp"

int main()
{
	ClapTrap guy("Michele");

	guy.attack("Agata");
	guy.takeDamage(2);
	guy.beRepaired(5);
	return 0;
}