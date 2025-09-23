#include "ScalarConverter.hpp"

// guarda come funzionano i cast senno non riesci a fare nulla rincoglionito di merda

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string input)
{
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
		return ;
	}
	else if (input == "inf" || input == "inff")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
		return ;
	}
	else if (input == "nan" || input == "nanf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
		return ;
	}

	if (parsInput(input) == true)
	{
		std::cout << "Wrong Input" << std::endl;
		return ;
	}

	toChar(input);
	toInt(input);
	toFloat(input);
	toDouble(input);
}


