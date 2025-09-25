#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Test 1: Valid Form creation and signing" << std::endl;
	try 
	{
		Bureaucrat alice("Alice", 20);
		Form contract("Contract", 30, 25);
		
		std::cout << alice << std::endl;
		std::cout << contract << std::endl;
		
		alice.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 2: Failed signing due to insufficient grade" << std::endl;
	try 
	{
		Bureaucrat intern("Intern", 100);
		Form importantDoc("Important Document", 10, 5);
		
		std::cout << intern << std::endl;
		std::cout << importantDoc << std::endl;
		
		intern.signForm(importantDoc);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 3: Invalid Form creation" << std::endl;
	try 
	{
		Form invalidForm("Invalid Form", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try 
	{
		Form invalidForm2("Invalid Form 2", 50, 200);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}