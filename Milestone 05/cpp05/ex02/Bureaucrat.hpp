#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string name;
		int grade;

	public:
		Bureaucrat(std::string name, int g);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const ;
		int getGrade() const ;
		void decrementGrade();
		void incrementGrade();

		void signForm(Form& form);

		class GradeTooHighException : public std::exception
		{
		public:
			// what() = metodo richiamato da std::exception
			// throw() = messo li perche specifica il tipo di eccezione 
			const char* what() const throw()
			{
				return "Grade is too high";
			}
		};
		
		class GradeTooLowException : public std::exception
		{
		public:
			const char* what() const throw()
			{
				return "Grade is too low";
			}
		};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);


#endif