#include "ScalarConverter.hpp"

int main(int argc,char **argv)
{
	if (argc != 2)
	{
		std::cout << "wring number of params" << std::endl;
		return (1);
	}
	ScalarConverter::convert(static_cast<std::string>(argv[2]));

	return (0);
}