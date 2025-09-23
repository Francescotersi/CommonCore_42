#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <iomanip>


class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(std::string);
};

void toChar(std::string input);
void toInt(std::string input);
void toFloat(std::string input);
void toDouble(std::string input);

bool parsInput(std::string input);

#endif