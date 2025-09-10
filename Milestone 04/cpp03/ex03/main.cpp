#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

// problema del diamante dell`ereditarieta multipla = 
// diamond eredita clpatrap sia da frag sia da scav
// cosi facendo si creano piu copie di Claprap provocando problemi di duplicazione
// ma se mettiamo l`ereditazione di frag e scav da claptrap cpme virtuale
// allora il linguaggio capisce di dover inizializzare Claptrap una sola volta per
// tutte e due le classi
int main()
{
	const std::string separator(90, '=');
	std::cout << separator << std::endl;

	DiamondTrap guy("Michele");

	guy.whoAmI();
	guy.attack("Agata");

	std::cout << separator << std::endl;

	DiamondTrap weakGuy("Weak");
	weakGuy.takeDamage(95);
	weakGuy.attack("LastEnemy");
	weakGuy.beRepaired(5);

	weakGuy.takeDamage(100);
	weakGuy.attack("Ghost");
	weakGuy.beRepaired(10);
	weakGuy.guardGate();
	
	return 0;
}