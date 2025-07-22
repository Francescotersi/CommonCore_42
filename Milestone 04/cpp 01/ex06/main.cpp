#include "Harl.hpp"

int	harlDictionary(char *level)
{
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			return (i);
	return (-1);
}

void	harlSwitch(char *argv, Harl harl)
{
	switch (harlDictionary(argv))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
	harlSwitch(argv[1], harl);
	return (0);
}
