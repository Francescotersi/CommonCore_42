#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToExec < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	this->sign = false;
	std::cout << "Constructing Form named = " << name << std::endl;
}

Form::Form(const Form& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	std::cout << "Constructing Form named = " << name << "from a copy" << std::endl;
	this->sign = other.sign;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructing Form named = " << this->name << std::endl;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getSign() const
{
	return this->sign;
}

int Form::getGradeToExec() const
{
	return this->gradeToExec;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

std::ostream& operator<<(std::ostream& output, const Form& form)
{
	output << "Form " << form.getName() << ", grade required to sign: " << form.getGradeToSign() 
		   << ", grade required to execute: " << form.getGradeToExec() 
		   << ", signed: " << (form.getSign() ? "yes" : "no");
    return output;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}
