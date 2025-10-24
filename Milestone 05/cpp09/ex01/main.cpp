#include "RPN.hpp"

void pars(std::string str)
{
	if (str == "+" || str == "-" || str == "/" || str == "*")
		return ;
	if (str.size() > 1)
		throw ErrorMessage("Error : something is too long 😏");
	if (!std::isdigit(static_cast<unsigned char>(str[0])))
		throw ErrorMessage("Error : there is an impostor among us");
}

void fillStack(std::stack<std::string> MyStack, std::string input)
{
	std::stringstream ss;
	std::string str;

	int	i = 0;
	ss << input;
	while (std::getline(ss, str, ' '))
	{
		if ((i < 2) && (str == "+" || str == "-" || str == "/" || str == "*"))
			throw ErrorMessage("Error : operator sign cant be there silly");
		if (str == "+" || str == "-" || str == "/" || str == "*")
			continue ;
		pars(str);
		MyStack.push(str);
		std::cout << "str = " << str << std::endl;
		i++;
	}
	if (MyStack.size() < 2)
		throw ErrorMessage("Error : input too short 😞");
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ErrorMessage("Error : wrong number of params");
		
		std::string input = argv[1];
		std::stack<std::string> MyStack;

		fillStack(MyStack, input);
		// itera l`input quando trovi operatore esegui operazione
		// dato che nello stack ci sono solamente numeri
		// usa ciclo for() o while() con switch() case
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	return 0;
}