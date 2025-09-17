#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExec;

	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const ;
		bool getSign() const ;
		int getGradeToSign() const ;
		int getGradeToExec() const ;

		void beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
		public:
			// what() = metodo richiamato da std::exception
			// throw() = messo li perche specifica il tipo di eccezione 
			const char* what() const throw()
			{
				return "Grade of the form is too high";
			}
		};
		
		class GradeTooLowException : public std::exception
		{
		public:
			const char* what() const throw()
			{
				return "Grade of the form is too low";
			}
		};
};

std::ostream& operator<<(std::ostream& output, const Form& Form);


#endif