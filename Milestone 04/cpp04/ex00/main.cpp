#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// - A virtual function (also known as virtual methods) is a member 
// function that is declared within a base class and is re-defined
// (overridden) by a derived class.
// - Virtual functions ensure that the correct function is called for
// an object, regardless of the type of reference (or pointer) used for the function call.
int main( void )
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Dog->getType = [" << dog->getType() << "] " << std::endl;
	std::cout << "Cat->getType = [" << cat->getType() << "] " << std::endl;
	cat->makeSound(); //will output the cat sound! (not the Animal)
	dog->makeSound(); //will output the dog sound! (not the Animal)
	animal->makeSound(); //will output the animal sound

	std::cout << std::endl;

	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;
	wrong_cat->makeSound();
	wrong_animal->makeSound();

	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_animal;
	delete wrong_cat;

	return 0;
}