#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	private:
		std::string type;
	
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();

		void makeSound() const ;
		std::string getType() const;
};

#endif
