
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing Bureaucrat Creation ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 150);
		Bureaucrat charlie("Charlie", 75);
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Forms Creation ===" << std::endl;
	try {
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("target1");
		PresidentialPardonForm pardon("criminal");
		
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Form Signing ===" << std::endl;
	try {
		Bureaucrat highRank("HighRank", 1);
		Bureaucrat lowRank("LowRank", 150);
		ShrubberyCreationForm shrub("test_shrub");
		
		std::cout << "Before signing: " << shrub << std::endl;

		highRank.signForm(shrub);
		std::cout << "After signing: " << shrub << std::endl;

		RobotomyRequestForm robot("test_robot");
		lowRank.signForm(robot);
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Form Execution ===" << std::endl;
	try {
		Bureaucrat executor("Executor", 1);
		Bureaucrat lowGrade("LowGrade", 150);

		ShrubberyCreationForm shrub("home");
		executor.signForm(shrub);
		executor.executeForm(shrub);

		RobotomyRequestForm unsignedRobot("unsigned_target");
		executor.executeForm(unsignedRobot);
		
		PresidentialPardonForm pardon("prisoner");
		executor.signForm(pardon);
		lowGrade.executeForm(pardon);
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing All Forms with Different Grades ===" << std::endl;
	try {
		Bureaucrat grade5("Grade5", 5);
		Bureaucrat grade25("Grade25", 25);
		Bureaucrat grade45("Grade45", 45);
		Bureaucrat grade72("Grade72", 72);
		Bureaucrat grade137("Grade137", 137);
		Bureaucrat grade145("Grade145", 145);
		
		ShrubberyCreationForm shrub("office");
		RobotomyRequestForm robot("employee");
		PresidentialPardonForm pardon("citizen");
		
		std::cout << "\n--- Testing ShrubberyCreationForm (sign: 145, exec: 137) ---" << std::endl;
		grade145.signForm(shrub);
		grade137.executeForm(shrub);
		
		std::cout << "\n--- Testing RobotomyRequestForm (sign: 72, exec: 45) ---" << std::endl;
		grade72.signForm(robot);
		grade45.executeForm(robot);
		
		std::cout << "\n--- Testing PresidentialPardonForm (sign: 25, exec: 5) ---" << std::endl;
		grade25.signForm(pardon);
		grade5.executeForm(pardon);
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Edge Cases ===" << std::endl;
	try {
		// Test invalid bureaucrat creation
		std::cout << "Trying to create bureaucrat with grade 0:" << std::endl;
		Bureaucrat invalid1("Invalid1", 0);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "Trying to create bureaucrat with grade 151:" << std::endl;
		Bureaucrat invalid2("Invalid2", 151);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Multiple Executions ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot1("target1");
		RobotomyRequestForm robot2("target2");
		RobotomyRequestForm robot3("target3");
		
		boss.signForm(robot1);
		boss.signForm(robot2);
		boss.signForm(robot3);

		for (int i = 0; i < 3; i++) {
			std::cout << "\nExecution " << (i + 1) << ":" << std::endl;
			boss.executeForm(robot1);
			boss.executeForm(robot2);
			boss.executeForm(robot3);
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

