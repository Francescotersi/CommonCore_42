#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , target(target)
{
	std::cout << "constructing PresidentialPardonForm from default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getGradeToExec(), other.getGradeToSign()) , target(other.target)
{
	std::cout << "constructing PresidentialPardonForm from a copy" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destructing PresidentialPardonForm" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == true && executor.getGrade() <= this->getGradeToExec())
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw GradeTooLowToExecute();
}