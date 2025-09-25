#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , target(target)
{
	std::cout << "constructing ShrubberyCreationForm from default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getGradeToExec(), other.getGradeToSign()) , target(other.target)
{
	std::cout << "constructing ShrubberyCreationForm from a copy" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destructing ShrubberyCreationForm" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == true && executor.getGrade() <= this->getGradeToExec())
	{
		std::ofstream File((this->target + "_shrubbery").c_str());
		File << "       /\\       " << std::endl;
		File << "      /  \\      " << std::endl;
		File << "     /____\\     " << std::endl;
		File << "    /\\    /\\    " << std::endl;
		File << "   /  \\  /  \\   " << std::endl;
		File << "  /____\\/____\\  " << std::endl;
		File << " /\\          /\\ " << std::endl;
		File << "/  \\        /  \\" << std::endl;
		File << "\\___\\      /___/" << std::endl;
		File << "     |    |       " << std::endl;
		File << "     |    |       " << std::endl;
		File << "     |____|       " << std::endl;
		File << "                  " << std::endl;
		File << "   ASCII Tree     " << std::endl;
		File.close();
	}
	else
		throw GradeTooLowToExecute();
}


