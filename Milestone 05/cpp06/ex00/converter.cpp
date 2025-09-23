#include "ScalarConverter.hpp"

void toChar(std::string input)
{
	char temp = 0;

	for (int i = 0; i < static_cast<int>(input.length()); i++)
	{
		if (!std::isprint(input[i]))
		{
			std::cout << "char : Non displayable" << std::endl;
			return ;
		}
	}

	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		temp = input[0];
		std::cout << "char : " << temp << std::endl;
	}
	else
	{
		int character = std::atoi(input.c_str());
		if (character >= 32 && character < 127)
			std::cout << "char : " << static_cast<char>(character) << std::endl;
		else
			std::cout << "char : non displayable" << std::endl;
	}
}

void toInt(std::string input, bool isLetter)
{
	if (isLetter)
	{
		int number = static_cast<int>(input[0]);
		std::cout << "int : " << number << std::endl;
		return ;		
	}
	if (input.length() < 10)
	{
		int number = static_cast<int>(std::atoi(input.c_str()));
		std::cout << "int : " << number << std::endl;
	}
	else
	{
		long temp = std::atol(input.c_str());
		if (temp > INT_MIN && temp < INT_MAX)
			std::cout << "int : " << static_cast<int>(temp) << std::endl;
		else
			std::cout << "int : out of int capacity" << std::endl;
	}
}

void toFloat(std::string input, bool isLetter)
{
	if (isLetter)
	{
		float number = static_cast<float>(input[0]);
        std::cout << "float: " << std::fixed << std::setprecision(1) << number << "f" << std::endl;
		return ;
	}
	float number = static_cast<float>(std::atof(input.c_str()));

    if (number == static_cast<int>(number))
        std::cout << "float: " << std::fixed << std::setprecision(1) << number << "f" << std::endl;
    else
        std::cout << "float: " << std::setprecision(6) << number << "f" << std::endl;
}

void toDouble(std::string input, bool isLetter)
{
	if (isLetter)
	{
		double number = static_cast<double>(input[0]);
        std::cout << "double: " << std::fixed << std::setprecision(1) << number << std::endl;
		return ;
	}
	double number = std::atof(input.c_str());

    if (number == static_cast<int>(number))
        std::cout << "double: " << std::fixed << std::setprecision(1) << number << std::endl;
    else
        std::cout << "double: " << std::setprecision(15) << number << std::endl;
}

bool parsInput(std::string input)
{
	int count = 0;
	
	for (int i = 0; i < static_cast<int>(input.length()); i++)
	{
		if ((input[i] >= 65 && input [i] <= 90) || (input[i] >= 97 && input[i] <= 122))
			count++;
		if (count >= 1 && (input[i] >= 48 && input [i] <= 57))
			return (true);
	}
	if (count == 1 && input[input.length() - 1] == 'f')
		return (false);
	if (count > 1)
		return (true);
	return (false);
}