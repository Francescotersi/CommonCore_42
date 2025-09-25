#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) , target(target)
{
	std::srand(time(0));
	std::cout << "constructing RobotomyRequestForm from default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToExec(), other.getGradeToSign()) , target(other.target)
{
	std::cout << "constructing RobotomyRequestForm from a copy" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destructing RobotomyRequestForm" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == true && executor.getGrade() <= this->getGradeToExec())
	{
		if (std::rand() % 2)
		{
			std::cout << target << " has been robotomized" << std::endl;
		}
		else
		{
			std::cout << target << " failed to be robotomized" << std::endl;
		}
	}
	else
		throw GradeTooLowToExecute();
}
