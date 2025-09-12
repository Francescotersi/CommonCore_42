// #include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	std::cout << "=== TESTING ABSTRACT CLASS ANIMAL ===" << std::endl;

	// ❌ QUESTA RIGA NON COMPILEREBBE - Animal è astratta!
	// Animal animal; // ERROR: cannot instantiate abstract class

	std::cout << "\n--- Test 1: Polymorphism with Abstract Base ---" << std::endl;
	{
		std::cout << "Creating animals through base class pointers:" << std::endl;
		const Animal* animals[4] = {
			new Dog(),
			new Cat(), 
			new Dog(),
			new Cat()
		};

		std::cout << "\nTesting polymorphic behavior:" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
			animals[i]->makeSound(); // Chiamata polimorfa - DEVE essere implementata!
		}

		std::cout << "\nCleaning up:" << std::endl;
		for (int i = 0; i < 4; i++) {
			delete animals[i];
		}
	}

	std::cout << "\n--- Test 2: Abstract Class Ensures Implementation ---" << std::endl;
	{
		std::cout << "Direct instantiation test:" << std::endl;
		Dog dog;
		Cat cat;
		
		std::cout << "Dog: ";
		dog.makeSound(); // Deve essere implementato in Dog
		
		std::cout << "Cat: ";
		cat.makeSound(); // Deve essere implementato in Cat
		
		// Polymorphism test
		Animal* animalPtr1 = &dog;
		Animal* animalPtr2 = &cat;
		
		std::cout << "Through Animal pointer - Dog: ";
		animalPtr1->makeSound();
		
		std::cout << "Through Animal pointer - Cat: ";
		animalPtr2->makeSound();
	}

	std::cout << "\n--- Test 3: Deep Copy with Abstract Base ---" << std::endl;
	{
		std::cout << "Testing deep copy functionality:" << std::endl;
		
		Cat originalCat;
		Cat copiedCat(originalCat);
		
		std::cout << "Original cat: ";
		originalCat.makeSound();
		std::cout << "Copied cat: ";
		copiedCat.makeSound();
		
		Dog originalDog;
		Dog assignedDog;
		assignedDog = originalDog;
		
		std::cout << "Original dog: ";
		originalDog.makeSound();
		std::cout << "Assigned dog: ";
		assignedDog.makeSound();
	}

	std::cout << "\n--- Test 4: Virtual Destructor Test ---" << std::endl;
	{
		std::cout << "Testing proper destruction through base pointer:" << std::endl;
		Animal* animal1 = new Cat();
		Animal* animal2 = new Dog();
		
		animal1->makeSound();
		animal2->makeSound();
		
		std::cout << "Deleting through Animal pointers:" << std::endl;
		delete animal1; // Should call Cat destructor properly
		delete animal2; // Should call Dog destructor properly
	}

	std::cout << "\n=== ABSTRACT CLASS TESTS COMPLETED ===" << std::endl;
	std::cout << "\nKey points demonstrated:" << std::endl;
	std::cout << "✓ Cannot instantiate abstract Animal class" << std::endl;
	std::cout << "✓ Must implement pure virtual makeSound() in derived classes" << std::endl;
	std::cout << "✓ Polymorphism works correctly" << std::endl;
	std::cout << "✓ Virtual destructor ensures proper cleanup" << std::endl;
	std::cout << "✓ Deep copy still works with abstract base" << std::endl;

	return 0;
}
