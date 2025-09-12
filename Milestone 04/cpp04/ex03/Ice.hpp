#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class ICharacter; // Forward declaration

class Ice : public AMateria
{
	private:
		std::string type;
	
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif