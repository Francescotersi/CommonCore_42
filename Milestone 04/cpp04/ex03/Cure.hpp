#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class ICharacter; // Forward declaration

class Cure : public AMateria
{
	private:
		std::string type;
	
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();		

		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif