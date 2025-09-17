#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToExec < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	this->sign = false;
	std::cout << "Constructing Form named = " << name << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	std::cout << "Constructing Form named = " << name << "from a copy" << std::endl;
	this->sign = other.sign;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructing Form named = " << this->name << std::endl;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getSign() const
{
	return this->sign;
}

int AForm::getGradeToExec() const
{
	return this->gradeToExec;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

std::ostream& operator<<(std::ostream& output, const AForm& form)
{
	output << "Form " << form.getName() << ", grade required to sign: " << form.getGradeToSign() 
		   << ", grade required to execute: " << form.getGradeToExec() 
		   << ", signed: " << (form.getSign() ? "yes" : "no");
    return output;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}
