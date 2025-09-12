// #include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	std::cout << "=== DEEP COPY TESTS ===" << std::endl;

	std::cout << "\n--- Test 1: Cat Copy Constructor ---" << std::endl;
	{
		std::cout << "Creating original cat:" << std::endl;
		Cat originalCat;
		
		std::cout << "\nCreating copy using copy constructor:" << std::endl;
		Cat copiedCat(originalCat);
		
		std::cout << "\nBoth cats should have different Brain addresses:" << std::endl;
		std::cout << "Original cat making sound:" << std::endl;
		originalCat.makeSound();
		std::cout << "Copied cat making sound:" << std::endl;
		copiedCat.makeSound();
		
		std::cout << "\nDestroying both cats (should not double-delete Brain):" << std::endl;
	} // Both cats go out of scope here

	std::cout << "\n--- Test 2: Cat Assignment Operator ---" << std::endl;
	{
		std::cout << "Creating two separate cats:" << std::endl;
		Cat cat1;
		Cat cat2;
		
		std::cout << "\nAssigning cat1 to cat2:" << std::endl;
		cat2 = cat1;
		
		std::cout << "\nBoth cats making sound:" << std::endl;
		cat1.makeSound();
		cat2.makeSound();
		
		std::cout << "\nDestroying both cats:" << std::endl;
	}

	std::cout << "\n--- Test 3: Dog Copy Constructor ---" << std::endl;
	{
		std::cout << "Creating original dog:" << std::endl;
		Dog originalDog;
		
		std::cout << "\nCreating copy using copy constructor:" << std::endl;
		Dog copiedDog(originalDog);
		
		std::cout << "\nBoth dogs making sound:" << std::endl;
		originalDog.makeSound();
		copiedDog.makeSound();
		
		std::cout << "\nDestroying both dogs:" << std::endl;
	}

	std::cout << "\n--- Test 4: Dog Assignment Operator ---" << std::endl;
	{
		std::cout << "Creating two separate dogs:" << std::endl;
		Dog dog1;
		Dog dog2;
		
		std::cout << "\nAssigning dog1 to dog2:" << std::endl;
		dog2 = dog1;
		
		std::cout << "\nBoth dogs making sound:" << std::endl;
		dog1.makeSound();
		dog2.makeSound();
		
		std::cout << "\nDestroying both dogs:" << std::endl;
	}

	// std::cout << "\n--- Test 5: Self Assignment ---" << std::endl;
	// {
	// 	std::cout << "Creating cat and testing self-assignment:" << std::endl;
	// 	Cat cat;
	// 	cat = cat; // Should handle self-assignment properly
	// 	std::cout << "Self-assignment completed, cat making sound:" << std::endl;
	// 	cat.makeSound();
	// }

	std::cout << "\n--- Test 6: Chain Assignment ---" << std::endl;
	{
		std::cout << "Creating three cats for chain assignment:" << std::endl;
		Cat cat1, cat2, cat3;
		
		std::cout << "\nChain assignment: cat3 = cat2 = cat1" << std::endl;
		cat3 = cat2 = cat1;
		
		std::cout << "\nAll three cats making sound:" << std::endl;
		cat1.makeSound();
		cat2.makeSound();
		cat3.makeSound();
	}

	std::cout << "\n=== ALL DEEP COPY TESTS COMPLETED ===" << std::endl;
	return 0;
}