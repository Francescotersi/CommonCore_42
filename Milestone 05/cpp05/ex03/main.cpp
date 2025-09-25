#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	std::cout << "Test 1: Valid form creation by Intern" << std::endl;
	try {
		Intern intern;
		AForm* shrub = intern.makeForm("shrubbery creation", "garden");
		AForm* robot = intern.makeForm("robotomy request", "target");
		AForm* pardon = intern.makeForm("presidential pardon", "criminal");
		
		if (shrub) {
			std::cout << *shrub << std::endl;
			delete shrub;
		}
		if (robot) {
			std::cout << *robot << std::endl;
			delete robot;
		}
		if (pardon) {
			std::cout << *pardon << std::endl;
			delete pardon;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 2: Invalid form name" << std::endl;
	try {
		Intern intern;
		AForm* invalid = intern.makeForm("invalid form", "target");
		
		if (invalid) {
			delete invalid;
		} else {
			std::cout << "Form creation failed as expected" << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 3: Complete workflow with Intern-created forms" << std::endl;
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm* form = intern.makeForm("shrubbery creation", "office");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

