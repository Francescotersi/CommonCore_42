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

void fillStack(std::stack<float> MyStack, std::string input)
{
	std::stringstream ss;
	std::string str;

	int	i = 0;
	int numbers = 0;
	int signs = 0;
	ss << input;

	for (int i = 0; input[i]; i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			signs++;
		}
		else if (std::isdigit(input[i]))
			numbers++;
	}
	if (numbers - signs != 1)
		throw ErrorMessage("Error : wrong numbers of signs and numbers");


	while (std::getline(ss, str, ' '))
	{
		if ((i < 2) && (str == "+" || str == "-" || str == "/" || str == "*"))
			throw ErrorMessage("Error : operator sign cant be there silly");
		if (str == "+" || str == "-" || str == "/" || str == "*")
			continue ;
		pars(str);	
		MyStack.push(std::atoi(str.c_str()));
		i++;
	}
	if (MyStack.size() < 2)
		throw ErrorMessage("Error : input too short 😞");
}

void reversePolishNotation(std::stack<float> *MyStack, std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		float num1 = 0;
		float num2 = 0;

		if (std::isdigit(input[i]))
			MyStack->push(std::atof(&input[i]));
		else if (input[i] == ' ')
			continue ;
		else
		{
			num1 = MyStack->top();
			MyStack->pop();
			num2 = MyStack->top();
			MyStack->pop();
			switch (input[i])
			{
			case '+':	
				MyStack->push(num2 + num1);
				break;
			case '-':
				MyStack->push(num2 - num1);
				break;
			case '*':
				MyStack->push(num2 * num1);
				break;
			case '/':
				if (num1 == 0)
					throw ErrorMessage("Error : division with 0 is not possible");
				else
					MyStack->push(num2 / num1);
				break;
	
			default:
				break;
			}
		}
	}
	if (MyStack->size() != 1)
		throw ErrorMessage("Error : invalid expression");

	std::cout << "result => " << MyStack->top() << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ErrorMessage("Error : wrong number of params");
		
		std::string input = argv[1];
		std::stack<float> MyStack;

		fillStack(MyStack, input);
		reversePolishNotation(&MyStack, input);
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
