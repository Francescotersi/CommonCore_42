#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

// una classe astratta e` una classe che non puo essere usata
// per creare altri oggetti direttamente. dovrebbe essere utilizzata
// come una normale interfaccia ma non definisce il comportamento
// della classe figlia
// A pure virtual function is a function declared in a base class
// that must be overridden in any derived class.

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void makeSound() const = 0; // funzione virtuale pura;   0 = no default implementation
		virtual std::string getType() const;
};


#endif