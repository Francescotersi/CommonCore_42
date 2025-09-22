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
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (!std::isprint(input[i]))
			std::cout << "Input contains characters that are not printable" << std::endl;
	}
	toChar(input);
}


