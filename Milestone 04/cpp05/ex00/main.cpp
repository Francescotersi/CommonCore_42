#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== TEST 1: Creazione Bureaucrat valido ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Errore: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 2: Eccezione grado troppo alto (< 1) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 3: Eccezione grado troppo basso (> 150) ===" << std::endl;
	try {
		Bureaucrat invalid2("Invalid2", 151);
		std::cout << invalid2 << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 4: Incremento e decremento grado ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 50);
		std::cout << "Iniziale: " << alice << std::endl;
		
		alice.incrementGrade();
		std::cout << "Dopo incremento: " << alice << std::endl;
		
		alice.decrementGrade();
		alice.decrementGrade();
		std::cout << "Dopo 2 decrementi: " << alice << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Errore: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 5: Test limiti estremi ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		std::cout << "Creato: " << boss << std::endl;

		Bureaucrat intern("Intern", 150);
		std::cout << "Creato: " << intern << std::endl;

		std::cout << "Tentativo di incrementare Boss oltre il limite..." << std::endl;
		boss.incrementGrade();
		
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat intern2("Intern2", 150);
		std::cout << "Tentativo di decrementare Intern oltre il limite..." << std::endl;
		intern2.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	return 0;
}