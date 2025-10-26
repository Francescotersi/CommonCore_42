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
    std::size_t stackSize = MyStack->size();
    if (stackSize == 0)
        return;

    int *temp = new int[stackSize];

    for (std::size_t i = 0; i < stackSize; ++i)
    {
        temp[i] = MyStack->top();
        MyStack->pop();
    }

	for (std::size_t i = 0; i < stackSize; ++i)
	{
		MyStack->push(temp[i]);
		// std:: cout << "after : i = " << (i - 1) << " | temp = " << temp[i - 1] << std::endl;
	}
	
    delete [] temp;
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
				MyStack->pop();
				num2 = MyStack->top();
				MyStack->pop();
				MyStack->push(num1 + num2);
				std::cout << "num1 = " << num1 << " ; num2 = " << num2 << std::endl;
				break ; 
			case '-':
				num1 = MyStack->top();
				MyStack->pop();
				num2 = MyStack->top();
				MyStack->pop();
				MyStack->push(num1 - num2);
				std::cout << "num1 = " << num1 << " ; num2 = " << num2 << std::endl;
				break ; 	
			case '*':
				num1 = MyStack->top();
				MyStack->pop();
				num2 = MyStack->top();
				MyStack->pop();
				MyStack->push(num1 * num2);
				std::cout << "num1 = " << num1 << " ; num2 = " << num2 << std::endl;
				break ; 
			case '/':
				num1 = MyStack->top();
				MyStack->pop();
				num2 = MyStack->top();
				MyStack->pop();
				MyStack->push(num1 / num2);
				std::cout << "num1 = " << num1 << " ; num2 = " << num2 << std::endl;
				break ; 
		}
	}
	std::cout << "risultato = " << MyStack->top() << std::endl;
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