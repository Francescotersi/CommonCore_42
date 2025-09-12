#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string type;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;
		std::string getType() const;

};


#endif