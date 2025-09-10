#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

// protected e` come privated ma permette di accedere agli
// attributi protetti anche dalle classe che derivano gli attributi
class ClapTrap
{
	protected:
		std::string name;
		int	hitPoints;
		int energyPoints;
		int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( const ClapTrap& other );
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		std::string getName() const ;
		int getHitPoints() const ;
		int getEnergyPoints() const ;
		int getAttackDamage() const ;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif