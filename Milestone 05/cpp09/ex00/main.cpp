#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error : wrong number of arguments" << std::endl;
		return 1;
	}	

	try
	{
		BitcoinExchange bitcoin(argv[1]);

		bitcoin.CheckValidDate();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
