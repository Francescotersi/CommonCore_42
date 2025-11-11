#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cctype>

class ErrorMessage : public std::exception
{
	private:
		const char *message;
	public:
		ErrorMessage(const char* str) : message(str){}
		virtual const char* what() const throw()
		{
			return message;
		}
};


#endif