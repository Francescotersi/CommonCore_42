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

void invertStack(std::stack<int> *MyStack)
{
	int stackSize = MyStack->size();
	int temp[stackSize];

	for (int i = 0; i < stackSize; i++)
	{
		temp[i] = MyStack->top();
		MyStack->pop();
	}

	for (int i = stackSize; i > 0; i--)
		std::cout << "after : " << " i = " << i << " | temp = " << temp[i - 1] << std::endl;

}

void fillStack(std::stack<int> *MyStack, std::string input)
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
		MyStack->push(std::atoi(str.c_str()));
		// std::cout << "str = " << str<< std::endl;
		i++;
	}
	if (MyStack->size() < 2)
		throw ErrorMessage("Error : input too short 😞");
	invertStack(MyStack);
}

void reversePolishNotation(std::stack<int> *MyStack, std::string input)
{
	// (void)input;
	// (void)MyStack;
	for (size_t i = 0; input[i]; i++)
	{
		int num1 = 0;
		int num2 = 0;
		switch (input[i])
		{
			case '+':
				num1 = MyStack->top();
				MyStack->pop();               //problema di valgrind in questa parte di codice
				num2 = MyStack->top();
				MyStack->pop();
				MyStack->push(num1 + num2);
				std::cout << "top = " << MyStack->top() << std::endl;
				break ; 
			// case '-':

			// case '*':

			// case '/':

		}
	}
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ErrorMessage("Error : wrong number of params");
		
		std::string input = argv[1];
		std::stack<int> MyStack;

		fillStack(&MyStack, input);
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