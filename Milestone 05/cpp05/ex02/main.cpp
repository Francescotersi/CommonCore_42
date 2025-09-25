
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	// Test 1: Successful form signing and execution
	std::cout << "Test 1: Successful signing and execution" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");
		
		std::cout << boss << std::endl;
		std::cout << shrub << std::endl;
		
		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 2: Failed execution" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		RobotomyRequestForm robot("target");
		
		std::cout << intern << std::endl;
		std::cout << robot << std::endl;
		
		intern.signForm(robot);
		intern.executeForm(robot);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 3: Testing all three form types" << std::endl;
	try {
		Bureaucrat president("President", 1);
		
		ShrubberyCreationForm shrub("office");
		RobotomyRequestForm robot("employee");
		PresidentialPardonForm pardon("criminal");
		
		president.signForm(shrub);
		president.executeForm(shrub);
		
		president.signForm(robot);
		president.executeForm(robot);
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

