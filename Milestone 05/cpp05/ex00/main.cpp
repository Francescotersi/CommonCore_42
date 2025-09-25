#include "Bureaucrat.hpp"

int main()
{

	std::cout << "\n  TEST 1: Creazione Bureaucrat e operazioni base\n" << std::endl;
	try {
		Bureaucrat alice("Alice", 75);
		std::cout << "Creato: " << alice << std::endl;
		
		alice.incrementGrade();
		
		alice.decrementGrade();
		alice.decrementGrade();
		
	} catch (const std::exception& e) {
		std::cout << "Errore: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 2: Tentativo grado troppo alto (< 1)\n" << std::endl;
	try {
		Bureaucrat invalid("SuperBoss", 0);
		std::cout << "Non dovrebbe arrivare qui!" << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Eccezione catturata: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 3: Tentativo grado troppo basso (> 150)\n" << std::endl;
	try {
		Bureaucrat intern("Useless", 200);
		std::cout << " Non dovrebbe arrivare qui!" << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Eccezione catturata: " << e.what() << std::endl;
	}

	std::cout << "\nTutti i test completati!\n" << std::endl;
	return 0;
}