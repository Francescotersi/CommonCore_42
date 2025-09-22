#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing Intern Creation ===" << std::endl;
	{
		Intern intern;
		Intern intern2(intern);
		Intern intern3 = intern;
		std::cout << "Interns created successfully" << std::endl;
	}

	std::cout << "\n=== Testing Valid Form Creation ===" << std::endl;
	try {
		Intern intern;
		AForm* form1 = intern.makeForm("shrubbery creation", "garden");
		AForm* form2 = intern.makeForm("robotomy request", "target");
		AForm* form3 = intern.makeForm("presidential pardon", "criminal");
		
		if (form1) {
			std::cout << *form1 << std::endl;
			delete form1;
		}
		if (form2) {
			std::cout << *form2 << std::endl;
			delete form2;
		}
		if (form3) {
			std::cout << *form3 << std::endl;
			delete form3;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Invalid Form Names ===" << std::endl;
	try {
		Intern intern;
		AForm* invalid1 = intern.makeForm("invalid form", "target");
		AForm* invalid2 = intern.makeForm("", "target");
		AForm* invalid3 = intern.makeForm("SHRUBBERY CREATION", "target");
		
		if (invalid1) delete invalid1;
		if (invalid2) delete invalid2;
		if (invalid3) delete invalid3;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Forms Created by Intern with Bureaucrats ===" << std::endl;
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		Bureaucrat lowLevel("LowLevel", 150);
		
		// Test ShrubberyCreationForm
		AForm* shrub = intern.makeForm("shrubbery creation", "office");
		if (shrub) {
			boss.signForm(*shrub);
			boss.executeForm(*shrub);
			delete shrub;
		}
		
		// Test RobotomyRequestForm
		AForm* robot = intern.makeForm("robotomy request", "employee");
		if (robot) {
			boss.signForm(*robot);
			boss.executeForm(*robot);
			delete robot;
		}
		
		// Test PresidentialPardonForm
		AForm* pardon = intern.makeForm("presidential pardon", "citizen");
		if (pardon) {
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Permission Failures ===" << std::endl;
	try {
		Intern intern;
		Bureaucrat weakBureaucrat("Weak", 150);
		
		AForm* difficultForm = intern.makeForm("presidential pardon", "prisoner");
		if (difficultForm) {
			weakBureaucrat.signForm(*difficultForm);
			weakBureaucrat.executeForm(*difficultForm);
			delete difficultForm;
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Multiple Form Creation ===" << std::endl;
	try {
		Intern intern;
		AForm* forms[6];
		
		forms[0] = intern.makeForm("shrubbery creation", "park");
		forms[1] = intern.makeForm("robotomy request", "android");
		forms[2] = intern.makeForm("presidential pardon", "rebel");
		forms[3] = intern.makeForm("shrubbery creation", "forest");
		forms[4] = intern.makeForm("robotomy request", "cyborg");
		forms[5] = intern.makeForm("presidential pardon", "activist");
		
		for (int i = 0; i < 6; i++) {
			if (forms[i]) {
				std::cout << "Form " << i + 1 << ": " << forms[i]->getName() << std::endl;
				delete forms[i];
			}
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test Complete ===" << std::endl;
	return 0;
}

