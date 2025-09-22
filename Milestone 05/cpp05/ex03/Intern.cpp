#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern()
{

}

Intern::Intern(const Intern& other) 
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {
		"robotomy request",
		"presidential pardon", 
		"shrubbery creation"
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
				case 0:
					return new RobotomyRequestForm(target);
				case 1:
					return new PresidentialPardonForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
			}
		}
	}
	
	std::cout << "Error: Form '" << formName << "' doesn't exist" << std::endl;
	return NULL;
}
