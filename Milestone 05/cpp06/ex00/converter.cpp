#include "ScalarConverter.hpp"

void toChar(std::string input)
{
	char temp = 0;

	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		temp = input[0];
		std::cout << "char : " << temp << std::endl;
	}
	else
	{
		int character = std::stoi(input);
		
	}

}