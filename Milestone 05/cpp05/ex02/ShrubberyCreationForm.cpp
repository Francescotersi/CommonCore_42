#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat& target) : AForm("ShrubberyCreationForm", 145, 137) , target(target)
{
	std::cout << "constructing Shrubbery from default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getGradeToExec(), other.getGradeToSign()) , target(other.target)
{
	std::cout << "constructing Shrubbery from a copy" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destructing ShrubberyCreationForm" << std::endl;
}

Bureaucrat& ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::createTreeFile() const
{
	if (this->getSign() == true && this->getGradeToExec() >= 137)
	{
		std::ofstream File(this->target.getName() + "_shrubbery");
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
}


