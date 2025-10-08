#include "easyfind.hpp"

int main()
{
	try 
	{
		std::vector<int> vector(4);
		vector[0] = 10;
		vector[1] = 20;
		vector[2] = 30;
		vector[3] = 40;

		easyfind(vector, 20);

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		std::vector<int> vector(3);
		vector[0] = 10;
		vector[1] = 20;
		vector[2] = 30;

		easyfind(vector, 40);

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		std::vector<char> vector(5);
		vector[0] = 'a';
		vector[1] = 'b';
		vector[2] = 'c';
		vector[3] = 'd';
		vector[4] = '0';

		easyfind(vector, 48);

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}