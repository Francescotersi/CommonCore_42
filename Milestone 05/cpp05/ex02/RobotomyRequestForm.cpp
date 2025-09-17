#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat& target) : AForm("RobotomyRequestForm", 145, 137) , target(target)
{
	std::cout << "constructing Shrubbery from default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToExec(), other.getGradeToSign()) , target(other.target)
{
	std::cout << "constructing Shrubbery from a copy" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destructing RobotomyRequestForm" << std::endl;
}

Bureaucrat& RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::randomRobotomize()
{
	std::srand(time(0));

	if (std::rand() % 2)
	{
		std::cout << "";
	}

}
